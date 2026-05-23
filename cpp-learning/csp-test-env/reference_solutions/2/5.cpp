#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;

using Matrix = vector<vector<long long>>;

Matrix multiply(const Matrix& a, const Matrix& b) {
    int n = (int)a.size();
    Matrix result(n, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            if (a[i][k] == 0) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (b[k][j] == 0) {
                    continue;
                }
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return result;
}

Matrix build_transition(int width) {
    int size = 1 << width;
    Matrix transition(size, vector<long long>(size));
    vector<vector<pair<int, int>>> shapes = {
        {{0, 0}, {1, 0}, {1, 1}},
        {{0, 1}, {1, 0}, {1, 1}},
        {{0, 0}, {0, 1}, {1, 0}},
        {{0, 0}, {0, 1}, {1, 1}},
    };

    function<void(int, int, int)> dfs = [&](int start_mask, int cur_mask, int next_mask) {
        int first = -1;
        for (int col = 0; col < width; ++col) {
            if (((cur_mask >> col) & 1) == 0) {
                first = col;
                break;
            }
        }
        if (first == -1) {
            transition[start_mask][next_mask] = (transition[start_mask][next_mask] + 1) % MOD;
            return;
        }

        for (const auto& shape : shapes) {
            for (auto [anchor_row, anchor_col] : shape) {
                int base_col = first - anchor_col;
                int new_cur = cur_mask;
                int new_next = next_mask;
                bool ok = true;
                for (auto [row, col] : shape) {
                    int real_row = row - anchor_row;
                    int real_col = col + base_col;
                    if (real_col < 0 || real_col >= width || real_row < 0 || real_row > 1) {
                        ok = false;
                        break;
                    }
                    if (real_row == 0) {
                        if ((new_cur >> real_col) & 1) {
                            ok = false;
                            break;
                        }
                        new_cur |= 1 << real_col;
                    } else {
                        if ((new_next >> real_col) & 1) {
                            ok = false;
                            break;
                        }
                        new_next |= 1 << real_col;
                    }
                }
                if (ok) {
                    dfs(start_mask, new_cur, new_next);
                }
            }
        }
    };

    for (int mask = 0; mask < size; ++mask) {
        dfs(mask, mask, 0);
    }
    return transition;
}

long long count_tilings(long long rows, int cols) {
    int size = 1 << cols;
    Matrix result(size, vector<long long>(size));
    for (int i = 0; i < size; ++i) {
        result[i][i] = 1;
    }
    Matrix power = build_transition(cols);
    while (rows > 0) {
        if (rows & 1LL) {
            result = multiply(result, power);
        }
        power = multiply(power, power);
        rows >>= 1LL;
    }
    return result[0][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;
    if (m > n) {
        swap(n, m);
    }
    cout << count_tilings(n, (int)m) << '\n';
    return 0;
}

