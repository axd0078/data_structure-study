#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> doc_count(m + 1), total_count(m + 1);
    vector<int> seen_stamp(m + 1, 0);

    for (int article = 1; article <= n; ++article) {
        int len;
        cin >> len;
        for (int j = 0; j < len; ++j) {
            int word;
            cin >> word;
            ++total_count[word];
            if (seen_stamp[word] != article) {
                seen_stamp[word] = article;
                ++doc_count[word];
            }
        }
    }

    for (int word = 1; word <= m; ++word) {
        cout << doc_count[word] << ' ' << total_count[word] << '\n';
    }
    return 0;
}
