#include <bits/stdc++.h>
using namespace std;

const long long NEG = -(1LL << 60);

struct Node {
    int next[26];
    int fail = 0;
    long long score = 0;
    Node() {
        fill(begin(next), end(next), -1);
    }
};

using Matrix = vector<vector<long long>>;

Matrix multiply(const Matrix& a, const Matrix& b) {
    int n = a.size();
    Matrix c(n, vector<long long>(n, NEG));
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            if (a[i][k] == NEG) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (b[k][j] == NEG) {
                    continue;
                }
                c[i][j] = max(c[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long m;
    cin >> n >> m;
    vector<Node> trie(1);
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        int u = 0;
        for (char ch : word) {
            int c = ch - 'a';
            if (trie[u].next[c] == -1) {
                trie[u].next[c] = trie.size();
                trie.emplace_back();
            }
            u = trie[u].next[c];
        }
        ++trie[u].score;
    }

    queue<int> q;
    for (int c = 0; c < 26; ++c) {
        int v = trie[0].next[c];
        if (v == -1) {
            trie[0].next[c] = 0;
        } else {
            q.push(v);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        trie[u].score += trie[trie[u].fail].score;
        for (int c = 0; c < 26; ++c) {
            int v = trie[u].next[c];
            if (v == -1) {
                trie[u].next[c] = trie[trie[u].fail].next[c];
            } else {
                trie[v].fail = trie[trie[u].fail].next[c];
                q.push(v);
            }
        }
    }

    int states = trie.size();
    Matrix trans(states, vector<long long>(states, NEG));
    for (int u = 0; u < states; ++u) {
        for (int c = 0; c < 26; ++c) {
            int v = trie[u].next[c];
            trans[u][v] = max(trans[u][v], trie[v].score);
        }
    }

    Matrix result(states, vector<long long>(states, NEG));
    for (int i = 0; i < states; ++i) {
        result[i][i] = 0;
    }
    while (m > 0) {
        if (m & 1LL) {
            result = multiply(result, trans);
        }
        trans = multiply(trans, trans);
        m >>= 1LL;
    }

    long long answer = 0;
    for (int j = 0; j < states; ++j) {
        answer = max(answer, result[0][j]);
    }
    cout << answer << '\n';
    return 0;
}
