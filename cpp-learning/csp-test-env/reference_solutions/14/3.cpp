#include <bits/stdc++.h>
using namespace std;

struct Node {
    int line;
    int depth;
    string tag;
    string id;
    vector<int> ancestors;
};

string lower_copy(string s) {
    for (char& c : s) c = (char)tolower((unsigned char)c);
    return s;
}

bool match_one(const Node& node, const string& selector) {
    if (!selector.empty() && selector[0] == '#') {
        return node.id == selector.substr(1);
    }
    return node.tag == lower_copy(selector);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string line;
    getline(cin, line);

    vector<Node> nodes;
    vector<int> last_at_depth(101, -1);
    for (int i = 1; i <= n; ++i) {
        getline(cin, line);
        int dots = 0;
        while (dots < (int)line.size() && line[dots] == '.') ++dots;
        int depth = dots / 2;
        string body = line.substr(dots);
        string tag, id;
        stringstream ss(body);
        ss >> tag;
        tag = lower_copy(tag);
        if (ss >> id) id = id.substr(1);

        vector<int> ancestors;
        for (int d = 0; d < depth; ++d) {
            ancestors.push_back(last_at_depth[d]);
        }
        nodes.push_back({i, depth, tag, id, ancestors});
        last_at_depth[depth] = (int)nodes.size() - 1;
    }

    while (m--) {
        getline(cin, line);
        stringstream ss(line);
        vector<string> selectors;
        string token;
        while (ss >> token) selectors.push_back(token);

        vector<int> answer;
        for (int idx = 0; idx < (int)nodes.size(); ++idx) {
            if (!match_one(nodes[idx], selectors.back())) continue;
            int need = (int)selectors.size() - 2;
            for (int p = (int)nodes[idx].ancestors.size() - 1; p >= 0 && need >= 0; --p) {
                int ancestor = nodes[idx].ancestors[p];
                if (ancestor >= 0 && match_one(nodes[ancestor], selectors[need])) {
                    --need;
                }
            }
            if (need < 0) answer.push_back(nodes[idx].line);
        }

        cout << answer.size();
        for (int x : answer) cout << ' ' << x;
        cout << '\n';
    }
    return 0;
}
