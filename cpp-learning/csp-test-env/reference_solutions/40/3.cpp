#include <bits/stdc++.h>
using namespace std;

void rotate_square(vector<string>& grid, int u, int v, int len, int degree) {
    --u;
    --v;
    int turns = ((degree / 90) % 4 + 4) % 4;
    vector<string> part(len, string(len, '?'));
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            part[i][j] = grid[u + i][v + j];
        }
    }
    while (turns--) {
        vector<string> next(len, string(len, '?'));
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                next[j][len - 1 - i] = part[i][j];
            }
        }
        part.swap(next);
    }
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            grid[u + i][v + j] = part[i][j];
        }
    }
}

void flip_rect(vector<string>& grid, int u, int d, int l, int r, int orient) {
    --u;
    --d;
    --l;
    --r;
    vector<string> part;
    for (int i = u; i <= d; ++i) {
        part.push_back(grid[i].substr(l, r - l + 1));
    }

    if (orient == 1) {
        reverse(part.begin(), part.end());
    } else {
        for (string& row : part) {
            reverse(row.begin(), row.end());
        }
    }

    for (int i = u; i <= d; ++i) {
        for (int j = l; j <= r; ++j) {
            grid[i][j] = part[i - u][j - l];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int z;
    cin >> z;
    vector<string> grid(z);
    for (int i = 0; i < z; ++i) {
        cin >> grid[i];
    }

    int k_size;
    cin >> k_size;
    vector<int> data(k_size);
    for (int i = 0; i < k_size; ++i) {
        cin >> data[i];
    }

    int t = data[0];
    int index = 1;
    for (int i = 0; i < t; ++i) {
        int op = data[index++];
        int a = data[index++];
        int b = data[index++];
        int c = data[index++];
        int d = data[index++];
        int e = data[index++];
        if (op == 1) {
            rotate_square(grid, a, b, c, d);
        } else {
            flip_rect(grid, a, b, c, d, e);
        }
    }

    int rows = 0, cols = 0;
    for (int i = 0; i < z; ++i) {
        for (int j = 0; j < z; ++j) {
            if (grid[i][j] != '?') {
                rows = max(rows, i + 1);
                cols = max(cols, j + 1);
            }
        }
    }

    cout << rows << ' ' << cols << '\n';
    for (int i = 0; i < rows; ++i) {
        cout << grid[i].substr(0, cols) << '\n';
    }
    return 0;
}
