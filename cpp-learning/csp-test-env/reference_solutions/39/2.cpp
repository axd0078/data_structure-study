#include <bits/stdc++.h>
using namespace std;

const vector<string> WATERMARK = {
    "*********",
    "*--*--*-*",
    "*--*****-",
    "*----**--",
    "*******--",
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, limit;
    cin >> n >> limit;
    vector<vector<int>> a(n, vector<int>(n));
    for (auto& row : a) {
        for (int& value : row) {
            cin >> value;
        }
    }

    vector<int> diff(limit + 1, 0);
    for (int top = 0; top + 5 <= n; ++top) {
        for (int left = 0; left + 9 <= n; ++left) {
            int min_white = limit - 1;
            int max_black = -1;
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 9; ++j) {
                    int value = a[top + i][left + j];
                    if (WATERMARK[i][j] == '*') {
                        min_white = min(min_white, value);
                    } else {
                        max_black = max(max_black, value);
                    }
                }
            }

            int low = max_black + 1;
            int high = min_white;
            if (low <= high) {
                ++diff[low];
                --diff[high + 1];
            }
        }
    }

    int active = 0;
    for (int k = 0; k < limit; ++k) {
        active += diff[k];
        if (active > 0) {
            cout << k << '\n';
        }
    }

    return 0;
}
