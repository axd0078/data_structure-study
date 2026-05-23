#include <bits/stdc++.h>
using namespace std;

string lower_copy(string s) {
    for (char& ch : s) {
        ch = (char)tolower((unsigned char)ch);
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string pattern;
    int sensitive;
    int n;
    cin >> pattern >> sensitive >> n;
    string query = sensitive ? pattern : lower_copy(pattern);
    while (n--) {
        string line;
        cin >> line;
        string target = sensitive ? line : lower_copy(line);
        if (target.find(query) != string::npos) {
            cout << line << '\n';
        }
    }
    return 0;
}

