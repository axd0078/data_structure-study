#include <bits/stdc++.h>
using namespace std;

struct Node {
    bool is_string = false;
    string value;
    map<string, Node> child;
};

struct Parser {
    string s;
    int pos = 0;

    void skip_space() {
        while (pos < (int)s.size() && isspace((unsigned char)s[pos])) ++pos;
    }

    string parse_string() {
        string out;
        ++pos;
        while (pos < (int)s.size()) {
            if (s[pos] == '\\') {
                out.push_back(s[pos + 1]);
                pos += 2;
            } else if (s[pos] == '"') {
                ++pos;
                break;
            } else {
                out.push_back(s[pos++]);
            }
        }
        return out;
    }

    Node parse_value() {
        skip_space();
        if (s[pos] == '"') {
            Node node;
            node.is_string = true;
            node.value = parse_string();
            return node;
        }
        return parse_object();
    }

    Node parse_object() {
        Node node;
        skip_space();
        ++pos;
        skip_space();
        if (s[pos] == '}') {
            ++pos;
            return node;
        }
        while (true) {
            skip_space();
            string key = parse_string();
            skip_space();
            ++pos;
            Node value = parse_value();
            node.child[key] = value;
            skip_space();
            if (s[pos] == '}') {
                ++pos;
                break;
            }
            ++pos;
        }
        return node;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string line, json;
    getline(cin, line);
    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        json += line;
        json += '\n';
    }

    Parser parser{json, 0};
    Node root = parser.parse_object();

    while (m--) {
        string query;
        cin >> query;
        Node* cur = &root;
        bool ok = true;
        int start = 0;
        while (start <= (int)query.size()) {
            int dot = (int)query.find('.', start);
            if (dot == -1) dot = (int)query.size();
            string key = query.substr(start, dot - start);
            if (cur->is_string || !cur->child.count(key)) {
                ok = false;
                break;
            }
            cur = &cur->child[key];
            start = dot + 1;
            if (dot == (int)query.size()) break;
        }

        if (!ok) {
            cout << "NOTEXIST\n";
        } else if (cur->is_string) {
            cout << "STRING " << cur->value << '\n';
        } else {
            cout << "OBJECT\n";
        }
    }
    return 0;
}
