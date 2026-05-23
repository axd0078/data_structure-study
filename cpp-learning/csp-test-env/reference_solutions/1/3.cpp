#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string spec;
    cin >> spec;
    map<char, bool> accepts;
    for (int i = 0; i < (int)spec.size();) {
        char option = spec[i];
        bool has_arg = (i + 1 < (int)spec.size() && spec[i + 1] == ':');
        accepts[option] = has_arg;
        i += has_arg ? 2 : 1;
    }

    int n;
    cin >> n;
    string line;
    getline(cin, line);
    for (int case_id = 1; case_id <= n; ++case_id) {
        getline(cin, line);
        stringstream ss(line);
        vector<string> tokens;
        string token;
        while (ss >> token) {
            tokens.push_back(token);
        }

        map<char, string> args;
        set<char> flags;
        int pos = 1;
        while (pos < (int)tokens.size()) {
            string cur = tokens[pos];
            if (cur.size() != 2 || cur[0] != '-' || !accepts.count(cur[1])) {
                break;
            }
            char option = cur[1];
            if (accepts[option]) {
                if (pos + 1 >= (int)tokens.size()) {
                    break;
                }
                args[option] = tokens[pos + 1];
                flags.insert(option);
                pos += 2;
            } else {
                flags.insert(option);
                pos += 1;
            }
        }

        cout << "Case " << case_id << ":";
        for (char option : flags) {
            cout << " -" << option;
            if (accepts[option]) {
                cout << ' ' << args[option];
            }
        }
        cout << '\n';
    }
    return 0;
}

