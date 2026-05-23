#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    getline(cin, line);
    string initial = line.substr(1, line.size() - 2);

    int n;
    cin >> n;
    getline(cin, line);

    vector<array<int, 128>> jump(31);
    for (int ch = 0; ch < 128; ++ch) {
        jump[0][ch] = ch;
    }

    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        jump[0][(unsigned char)line[1]] = (unsigned char)line[2];
    }

    for (int bit = 1; bit < 31; ++bit) {
        for (int ch = 0; ch < 128; ++ch) {
            jump[bit][ch] = jump[bit - 1][jump[bit - 1][ch]];
        }
    }

    int m;
    cin >> m;
    while (m--) {
        int k;
        cin >> k;
        string result = initial;
        for (char& ch : result) {
            int cur = (unsigned char)ch;
            int value = k;
            int bit = 0;
            while (value > 0) {
                if (value & 1) {
                    cur = jump[bit][cur];
                }
                value >>= 1;
                ++bit;
            }
            ch = (char)cur;
        }
        cout << '#' << result << '#' << '\n';
    }

    return 0;
}
