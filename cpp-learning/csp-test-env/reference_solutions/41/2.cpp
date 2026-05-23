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

    auto greedy = [&](int left) {
        double saved = 0.0;
        double remain = left;
        for (const Task& task : flexible) {
            double take = min(remain, double(task.coffee));
            saved += take * task.saved / task.coffee;
            remain -= take;
            if (remain <= 0) {
                break;
            }
        }
        return saved;
    };

    double best_saved = 0.0;
    for (int used = 0; used <= m; ++used) {
        best_saved = max(best_saved, dp[used] + greedy(m - used));
    }

    cout << fixed << setprecision(6) << total_time - best_saved << '\n';
    return 0;
}
