#include <bits/stdc++.h>
using namespace std;

string render_line(const string& line, const unordered_map<string, string>& vars) {
    string out;
    for (size_t i = 0; i < line.size();) {
        if (i + 3 < line.size() && line[i] == '{' && line[i + 1] == '{' && line[i + 2] == ' ') {
            size_t end = line.find(" }}", i + 3);
            string name = line.substr(i + 3, end - (i + 3));
            auto it = vars.find(name);
            if (it != vars.end()) {
                out += it->second;
            }
            i = end + 3;
        } else {
            out.push_back(line[i]);
            ++i;
        }
    }
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    string line;
    getline(cin, line);
    vector<string> tmpl(m);
    for (int i = 0; i < m; ++i) {
        getline(cin, tmpl[i]);
    }

    unordered_map<string, string> vars;
    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        size_t space = line.find(' ');
        string name = line.substr(0, space);
        size_t first_quote = line.find('"', space);
        size_t last_quote = line.rfind('"');
        vars[name] = line.substr(first_quote + 1, last_quote - first_quote - 1);
    }

    for (const string& row : tmpl) {
        cout << render_line(row, vars) << '\n';
    }
    return 0;
}
