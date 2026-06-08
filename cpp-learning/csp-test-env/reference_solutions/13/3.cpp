#include <bits/stdc++.h>
using namespace std;

vector<string> split_path(const string& path) {
    string body = path.substr(1);
    vector<string> parts;
    string cur;
    for (char c : body) {
        if (c == '/') {
            parts.push_back(cur);
            cur.clear();
        } else {
            cur.push_back(c);
        }
    }
    parts.push_back(cur);
    return parts;
}

bool all_digits(const string& s) {
    return !s.empty() && all_of(s.begin(), s.end(), [](char c) { return isdigit((unsigned char)c); });
}

string trim_integer(const string& s) {
    int pos = 0;
    while (pos + 1 < (int)s.size() && s[pos] == '0') ++pos;
    return s.substr(pos);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pair<string, string>> rules(n);
    for (auto& rule : rules) {
        cin >> rule.first >> rule.second;
    }

    while (m--) {
        string query;
        cin >> query;
        vector<string> q = split_path(query);
        bool matched = false;
        for (auto [pattern, name] : rules) {
            vector<string> p = split_path(pattern);
            vector<string> args;
            bool ok = true;
            for (int i = 0, j = 0; ok && i < (int)p.size(); ++i, ++j) {
                if (p[i] == "<path>") {
                    if (j >= (int)q.size()) {
                        ok = false;
                    } else {
                        string rest = q[j];
                        for (int k = j + 1; k < (int)q.size(); ++k) rest += "/" + q[k];
                        if (rest.empty()) ok = false;
                        args.push_back(rest);
                        j = (int)q.size();
                    }
                    if (j != (int)q.size()) ok = false;
                    break;
                }
                if (j >= (int)q.size()) {
                    ok = false;
                } else if (p[i] == "<str>") {
                    if (q[j].empty()) ok = false;
                    else args.push_back(q[j]);
                } else if (p[i] == "<int>") {
                    if (!all_digits(q[j])) ok = false;
                    else args.push_back(trim_integer(q[j]));
                } else if (p[i] != q[j]) {
                    ok = false;
                }
                if (i + 1 == (int)p.size() && j + 1 != (int)q.size()) ok = false;
            }
            if (ok) {
                cout << name;
                for (const string& arg : args) cout << ' ' << arg;
                cout << '\n';
                matched = true;
                break;
            }
        }
        if (!matched) {
            cout << "404\n";
        }
    }
    return 0;
}
