#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch = 0;
    int left = -1;
    int right = -1;
};

vector<Node> tree;
string tree_spec;

int parse_tree(int& pos) {
    int id = (int)tree.size();
    tree.push_back(Node());
    if (tree_spec[pos] == '1') {
        pos++;
        tree[id].ch = tree_spec[pos++];
    } else {
        pos++;
        tree[id].left = parse_tree(pos);
        tree[id].right = parse_tree(pos);
    }
    return id;
}

int hex_value(char ch) {
    if ('0' <= ch && ch <= '9') {
        return ch - '0';
    }
    return ch - 'a' + 10;
}

string decode_string(const string& token) {
    if (token.empty() || token[0] != 'H') {
        return token;
    }
    if (token.size() >= 2 && token[1] == 'H') {
        return token.substr(1);
    }

    vector<int> bytes;
    for (int i = 1; i + 1 < (int)token.size(); i += 2) {
        bytes.push_back(hex_value(token[i]) * 16 + hex_value(token[i + 1]));
    }
    if (bytes.empty()) {
        return "";
    }

    int padding = bytes.back();
    bytes.pop_back();

    vector<int> bits;
    for (int value : bytes) {
        for (int bit = 7; bit >= 0; bit--) {
            bits.push_back((value >> bit) & 1);
        }
    }
    while (padding-- > 0 && !bits.empty()) {
        bits.pop_back();
    }

    string result;
    int cur = 0;
    for (int bit : bits) {
        cur = bit == 0 ? tree[cur].left : tree[cur].right;
        if (tree[cur].ch != 0) {
            result.push_back(tree[cur].ch);
            cur = 0;
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s_count, limit;
    cin >> s_count >> limit;

    vector<pair<string, string>> statics(s_count);
    for (auto& item : statics) {
        cin >> item.first >> item.second;
    }

    cin >> tree_spec;
    int pos = 0;
    parse_tree(pos);

    vector<pair<string, string>> dynamic;

    auto lookup = [&](int index) -> pair<string, string> {
        if (index <= s_count) {
            return statics[index - 1];
        }
        return dynamic[index - s_count - 1];
    };

    auto add_dynamic = [&](pair<string, string> item) {
        dynamic.insert(dynamic.begin(), move(item));
        if ((int)dynamic.size() > limit) {
            dynamic.pop_back();
        }
    };

    int n;
    cin >> n;
    while (n--) {
        int op, index;
        cin >> op >> index;

        string key, value;
        if (op == 1) {
            tie(key, value) = lookup(index);
        } else {
            bool indexed = op == 2;
            if (index == 0) {
                string raw_key, raw_value;
                cin >> raw_key >> raw_value;
                key = decode_string(raw_key);
                value = decode_string(raw_value);
            } else {
                tie(key, value) = lookup(index);
                string raw_value;
                cin >> raw_value;
                value = decode_string(raw_value);
            }
            if (indexed) {
                add_dynamic({key, value});
            }
        }

        cout << key << ": " << value << '\n';
    }

    return 0;
}
