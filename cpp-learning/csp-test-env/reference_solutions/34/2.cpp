#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int rows, cols, t;
    cin >> rows >> cols >> t;
    int total = rows * cols;
    vector<int> flat(total);
    for (int& value : flat) {
        cin >> value;
    }

    while (t--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1) {
            rows = a;
            cols = b;
        } else if (op == 2) {
            vector<int> transposed(total);
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    transposed[j * rows + i] = flat[i * cols + j];
                }
            }
            flat.swap(transposed);
            swap(rows, cols);
        } else {
            cout << flat[a * cols + b] << '\n';
        }
    }

    return 0;
}
