#include <bits/stdc++.h>
using namespace std;

using Matrix = vector<vector<unsigned long long>>;

Matrix multiply(const Matrix& a, const Matrix& b, int n, int blocks) {
    Matrix c(n, vector<unsigned long long>(blocks, 0));
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            if ((a[i][k >> 6] >> (k & 63)) & 1ULL) {
                for (int block = 0; block < blocks; ++block) {
                    c[i][block] ^= b[k][block];
                }
            }
        }
    }
    return c;
}

vector<unsigned long long> apply(const Matrix& a, const vector<unsigned long long>& v, int n, int blocks) {
    vector<unsigned long long> out(blocks, 0);
    for (int i = 0; i < n; ++i) {
        int bit = 0;
        for (int block = 0; block < blocks; ++block) {
            bit ^= (__builtin_popcountll(a[i][block] & v[block]) & 1);
        }
        if (bit) {
            out[i >> 6] |= 1ULL << (i & 63);
        }
    }
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;
    int blocks = (m + 63) / 64;
    Matrix base(m, vector<unsigned long long>(blocks, 0));
    string s;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '1') {
                base[i][j >> 6] |= 1ULL << (j & 63);
            }
        }
    }
    cin >> s;
    vector<unsigned long long> initial(blocks, 0);
    for (int i = 0; i < m; ++i) {
        if (s[i] == '1') {
            initial[i >> 6] |= 1ULL << (i & 63);
        }
    }

    vector<Matrix> power;
    power.push_back(base);
    for (int i = 1; i < 31; ++i) {
        power.push_back(multiply(power.back(), power.back(), m, blocks));
    }

    int q;
    cin >> q;
    while (q--) {
        long long k;
        cin >> k;
        vector<unsigned long long> v = initial;
        int bit = 0;
        while (k > 0) {
            if (k & 1LL) {
                v = apply(power[bit], v, m, blocks);
            }
            k >>= 1LL;
            ++bit;
        }
        for (int i = 0; i < m; ++i) {
            cout << (((v[i >> 6] >> (i & 63)) & 1ULL) ? '1' : '0');
        }
        cout << '\n';
    }
    return 0;
}
