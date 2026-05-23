#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> board(15, vector<int>(10));
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> board[i][j];
        }
    }

    vector<vector<int>> block(4, vector<int>(4));
    vector<pair<int, int>> cells;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> block[i][j];
            if (block[i][j] == 1) cells.push_back({i, j});
        }
    }

    int col;
    cin >> col;
    --col;

    auto can_place = [&](int top) {
        for (auto [r, c] : cells) {
            int nr = top + r;
            int nc = col + c;
            if (nr < 0 || nr >= 15 || nc < 0 || nc >= 10 || board[nr][nc]) {
                return false;
            }
        }
        return true;
    };

    int top = 0;
    while (can_place(top + 1)) {
        ++top;
    }
    for (auto [r, c] : cells) {
        board[top + r][col + c] = 1;
    }

    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (j) cout << ' ';
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}
