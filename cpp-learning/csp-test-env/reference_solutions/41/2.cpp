#include <bits/stdc++.h>
using namespace std;

struct Task {
    int coffee;
    double saved;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<Task> normal, flexible;
    double total_time = 0.0;

    for (int i = 0; i < n; ++i) {
        int type, t, a, b;
        cin >> type >> t >> a >> b;
        total_time += t;
        if (type == 0) {
            flexible.push_back({a, double(b)});
        } else {
            normal.push_back({a, double(b)});
        }
    }

    vector<double> dp(m + 1, 0.0);
    for (const Task& task : normal) {
        for (int used = m; used >= task.coffee; --used) {
            dp[used] = max(dp[used], dp[used - task.coffee] + task.saved);
        }
    }

    sort(flexible.begin(), flexible.end(), [](const Task& lhs, const Task& rhs) {
        return lhs.saved * rhs.coffee > rhs.saved * lhs.coffee;
    });

    vector<double> flexible_saved(m + 1, 0.0);
    int capacity = 0;
    double saved = 0.0;
    for (const Task& task : flexible) {
        for (int take = 1; take <= task.coffee && capacity < m; ++take) {
            ++capacity;
            saved += task.saved / task.coffee;
            flexible_saved[capacity] = saved;
        }
        if (capacity == m) {
            break;
        }
    }
    for (int i = capacity + 1; i <= m; ++i) {
        flexible_saved[i] = saved;
    }

    double best_saved = 0.0;
    for (int used = 0; used <= m; ++used) {
        best_saved = max(best_saved, dp[used] + flexible_saved[m - used]);
    }

    cout << fixed << setprecision(6) << total_time - best_saved << '\n';
    return 0;
}
