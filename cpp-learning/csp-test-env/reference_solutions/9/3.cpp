#include <bits/stdc++.h>
using namespace std;

struct Priv {
    string name;
    int level;
};

Priv parse_priv(const string& s) {
    size_t pos = s.find(':');
    if (pos == string::npos) {
        return {s, -1};
    }
    return {s.substr(0, pos), s[pos + 1] - '0'};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int p;
    cin >> p;
    unordered_map<string, int> defined;
    for (int i = 0; i < p; ++i) {
        string s;
        cin >> s;
        Priv priv = parse_priv(s);
        defined[priv.name] = priv.level;
    }

    int r;
    cin >> r;
    unordered_map<string, unordered_map<string, int>> roles;
    for (int i = 0; i < r; ++i) {
        string role;
        int count;
        cin >> role >> count;
        auto& mp = roles[role];
        for (int j = 0; j < count; ++j) {
            string s;
            cin >> s;
            Priv priv = parse_priv(s);
            int value = priv.level;
            if (!mp.count(priv.name) || value > mp[priv.name]) {
                mp[priv.name] = value;
            }
        }
    }

    int u;
    cin >> u;
    unordered_map<string, unordered_map<string, int>> users;
    for (int i = 0; i < u; ++i) {
        string user;
        int count;
        cin >> user >> count;
        auto& mp = users[user];
        for (int j = 0; j < count; ++j) {
            string role;
            cin >> role;
            for (auto [name, level] : roles[role]) {
                if (!mp.count(name) || level > mp[name]) {
                    mp[name] = level;
                }
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        string user, query;
        cin >> user >> query;
        Priv priv = parse_priv(query);
        if (!defined.count(priv.name) || !users.count(user) || !users[user].count(priv.name)) {
            cout << "false\n";
            continue;
        }

        int max_level = users[user][priv.name];
        if (defined[priv.name] == -1) {
            cout << "true\n";
        } else if (priv.level == -1) {
            cout << max_level << '\n';
        } else {
            cout << (max_level >= priv.level ? "true" : "false") << '\n';
        }
    }
    return 0;
}
