#include <bits/stdc++.h>
using namespace std;

string lower_word(string s) {
    for (char& ch : s) {
        ch = (char)tolower((unsigned char)ch);
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    set<string> a, b;
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        a.insert(lower_word(word));
    }
    for (int i = 0; i < m; ++i) {
        string word;
        cin >> word;
        b.insert(lower_word(word));
    }

    int intersection_size = 0;
    for (const string& word : a) {
        intersection_size += b.count(word);
    }
    int union_size = (int)a.size() + (int)b.size() - intersection_size;

    cout << intersection_size << '\n' << union_size << '\n';
    return 0;
}
