#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

struct Operation {
    int type;
    int l;
    int r;
    u64 value;
};

struct Node {
    i64 len = 0;
    i64 sum0 = 0;
    i64 tri0 = 0;
    vector<i64> sum;
    vector<i64> cross;
    vector<i64> lazy;
};

int n, m, digits_count;
i64 base_k;
vector<u64> powers_k;
vector<Node> tree;
vector<vector<i64>> initial_digits;

i64 mod_add(i64 a, i64 b) {
    a += b;
    if (a >= base_k) {
        a -= base_k;
    }
    return a;
}

i64 mod_mul(i64 a, i64 b) {
    return (i64)((i128)a * b % base_k);
}

i64 triangle_digit(i64 x) {
    return (i64)((i128)x * (x + 1) / 2 % base_k);
}

vector<i64> to_digits(u64 value) {
    vector<i64> digits(digits_count, 0);
    for (int i = 0; i < digits_count; ++i) {
        digits[i] = (i64)(value % (u64)base_k);
        value /= (u64)base_k;
    }
    return digits;
}

void init_node(int p) {
    tree[p].sum.assign(digits_count, 0);
    tree[p].cross.assign(digits_count, 0);
    tree[p].lazy.assign(digits_count, 0);
}

Node merge_nodes(const Node& left, const Node& right) {
    Node result;
    result.len = (left.len + right.len) % base_k;
    result.sum0 = (left.sum0 + right.sum0) % base_k;
    result.tri0 = (left.tri0 + right.tri0) % base_k;
    result.sum.assign(digits_count, 0);
    result.cross.assign(digits_count, 0);
    result.lazy.assign(digits_count, 0);
    for (int i = 0; i < digits_count; ++i) {
        result.sum[i] = (left.sum[i] + right.sum[i]) % base_k;
        result.cross[i] = (left.cross[i] + right.cross[i]) % base_k;
    }
    return result;
}

void pull(int p) {
    Node merged = merge_nodes(tree[p << 1], tree[p << 1 | 1]);
    tree[p].len = merged.len;
    tree[p].sum0 = merged.sum0;
    tree[p].tri0 = merged.tri0;
    tree[p].sum.swap(merged.sum);
    tree[p].cross.swap(merged.cross);
}

void apply_add(int p, const vector<i64>& delta) {
    i64 c0 = delta[0];
    i64 old_sum0 = tree[p].sum0;

    tree[p].tri0 = (tree[p].tri0 + mod_mul(c0, old_sum0) + mod_mul(tree[p].len, triangle_digit(c0))) % base_k;
    tree[p].sum0 = (tree[p].sum0 + mod_mul(tree[p].len, c0)) % base_k;
    tree[p].sum[0] = tree[p].sum0;

    for (int i = 1; i < digits_count; ++i) {
        i64 ci = delta[i];
        tree[p].cross[i] = (tree[p].cross[i] + mod_mul(c0, tree[p].sum[i]) + mod_mul(ci, old_sum0) + mod_mul(tree[p].len, mod_mul(ci, c0))) % base_k;
        tree[p].sum[i] = (tree[p].sum[i] + mod_mul(tree[p].len, ci)) % base_k;
    }
    for (int i = 0; i < digits_count; ++i) {
        tree[p].lazy[i] = (tree[p].lazy[i] + delta[i]) % base_k;
    }
}

void push(int p) {
    bool has_lazy = false;
    for (i64 value : tree[p].lazy) {
        if (value != 0) {
            has_lazy = true;
            break;
        }
    }
    if (!has_lazy) {
        return;
    }
    apply_add(p << 1, tree[p].lazy);
    apply_add(p << 1 | 1, tree[p].lazy);
    fill(tree[p].lazy.begin(), tree[p].lazy.end(), 0);
}

void build(int p, int l, int r) {
    init_node(p);
    if (l == r) {
        tree[p].len = 1 % base_k;
        const vector<i64>& digits = initial_digits[l];
        tree[p].sum0 = digits[0] % base_k;
        tree[p].tri0 = triangle_digit(digits[0]);
        for (int i = 0; i < digits_count; ++i) {
            tree[p].sum[i] = digits[i] % base_k;
            if (i > 0) {
                tree[p].cross[i] = mod_mul(digits[i], digits[0]);
            }
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    pull(p);
}

void update(int p, int l, int r, int ql, int qr, const vector<i64>& delta) {
    if (ql <= l && r <= qr) {
        apply_add(p, delta);
        return;
    }
    push(p);
    int mid = (l + r) >> 1;
    if (ql <= mid) {
        update(p << 1, l, mid, ql, qr, delta);
    }
    if (qr > mid) {
        update(p << 1 | 1, mid + 1, r, ql, qr, delta);
    }
    pull(p);
}

Node query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return tree[p];
    }
    push(p);
    int mid = (l + r) >> 1;
    if (qr <= mid) {
        return query(p << 1, l, mid, ql, qr);
    }
    if (ql > mid) {
        return query(p << 1 | 1, mid + 1, r, ql, qr);
    }
    Node left = query(p << 1, l, mid, ql, qr);
    Node right = query(p << 1 | 1, mid + 1, r, ql, qr);
    return merge_nodes(left, right);
}

void print_u128(__uint128_t value) {
    if (value == 0) {
        cout << 0;
        return;
    }
    string s;
    while (value > 0) {
        s.push_back(char('0' + value % 10));
        value /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> base_k;
    vector<u64> initial_values(n + 1);
    u64 max_value = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> initial_values[i];
        max_value = max(max_value, initial_values[i]);
    }

    vector<Operation> operations(m);
    for (int i = 0; i < m; ++i) {
        cin >> operations[i].type >> operations[i].l >> operations[i].r;
        operations[i].value = 0;
        if (operations[i].type == 1) {
            cin >> operations[i].value;
            max_value = max(max_value, operations[i].value);
        }
    }

    powers_k.push_back(1);
    __uint128_t current = 1;
    do {
        current *= (u64)base_k;
        powers_k.push_back((u64)current);
    } while (current <= max_value);
    digits_count = (int)powers_k.size();

    initial_digits.assign(n + 1, {});
    for (int i = 1; i <= n; ++i) {
        initial_digits[i] = to_digits(initial_values[i]);
    }

    tree.assign(4 * n + 5, {});
    build(1, 1, n);

    for (const Operation& op : operations) {
        if (op.type == 1) {
            vector<i64> delta = to_digits(op.value);
            update(1, 1, n, op.l, op.r, delta);
        } else {
            Node result = query(1, 1, n, op.l, op.r);
            __uint128_t answer = result.tri0;
            for (int i = 1; i < digits_count; ++i) {
                i64 digit = (result.cross[i] + result.sum[i]) % base_k;
                answer += (__uint128_t)digit * powers_k[i];
            }
            print_u128(answer);
            cout << '\n';
        }
    }
    return 0;
}
