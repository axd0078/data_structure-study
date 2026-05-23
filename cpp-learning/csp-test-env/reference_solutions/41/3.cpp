#include <bits/stdc++.h>
using namespace std;

const long long INF = 4000000000000000000LL;

struct Segment {
    long long l;
    long long r;

    long long len() const {
        return r - l + 1;
    }
};

struct ByLength {
    bool operator()(const Segment& lhs, const Segment& rhs) const {
        if (lhs.len() != rhs.len()) {
            return lhs.len() < rhs.len();
        }
        return lhs.l < rhs.l;
    }
};

struct QueueInfo {
    long long l;
    long long r;
    long long next;
};

map<long long, long long> free_by_left;
set<Segment, ByLength> free_by_length;

void add_free(long long l, long long r) {
    if (l > r) {
        return;
    }
    free_by_left[l] = r;
    free_by_length.insert({l, r});
}

void remove_free(long long l, long long r) {
    free_by_left.erase(l);
    free_by_length.erase({l, r});
}

long long allocate_block(long long length) {
    auto it = free_by_length.lower_bound({0, length - 1});
    Segment seg = *it;
    remove_free(seg.l, seg.r);

    long long start = seg.l;
    long long end = seg.l + length - 1;
    if (end + 1 <= seg.r) {
        add_free(end + 1, seg.r);
    }
    return start;
}

void release_block(long long l, long long r) {
    long long nl = l, nr = r;

    auto it = free_by_left.lower_bound(l);
    if (it != free_by_left.begin()) {
        auto prev_it = prev(it);
        if (prev_it->second + 1 == l) {
            nl = prev_it->first;
            remove_free(prev_it->first, prev_it->second);
        }
    }

    it = free_by_left.lower_bound(l);
    if (it != free_by_left.end() && r + 1 == it->first) {
        nr = it->second;
        remove_free(it->first, it->second);
    }

    add_free(nl, nr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<vector<QueueInfo>> proc(n + 1);
    add_free(0, INF);

    while (q--) {
        string op;
        cin >> op;
        if (op == "new") {
            int p;
            long long length;
            cin >> p >> length;
            long long start = allocate_block(length);
            proc[p].push_back({start, start + length - 1, start});
            cout << start << '\n';
        } else if (op == "delete") {
            int p, index;
            cin >> p >> index;
            --index;
            QueueInfo item = proc[p][index];
            proc[p].erase(proc[p].begin() + index);
            release_block(item.l, item.r);
        } else {
            int p;
            cin >> p;
            long long total = 0;
            for (QueueInfo& item : proc[p]) {
                total += item.next;
                ++item.next;
                if (item.next > item.r) {
                    item.next = item.l;
                }
            }
            cout << total << '\n';
        }
    }

    return 0;
}
