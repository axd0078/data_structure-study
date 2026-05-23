#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<array<int, 3>> task(n + 1);
    int limit_sum = 0;
    for (int i = 1; i <= n; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        task[i] = {a, c, min(b, d)};
        limit_sum += max({task[i][0], task[i][1], task[i][2]});
    }
    int limit = (limit_sum + 1) / 2;

    int state_count = (limit + 1) * (limit + 1) * (limit + 1);
    vector<int> prev(state_count, INF), cur(state_count, INF);

    auto id = [limit](int cpu1, int cpu2, int gpu) {
        return (cpu1 * (limit + 1) + cpu2) * (limit + 1) + gpu;
    };

    prev[id(0, 0, 0)] = 0;
    for (int u = 1; u <= n; ++u) {
        fill(cur.begin(), cur.end(), INF);
        int one_cpu = task[u][0];
        int cpu_gpu = task[u][1];
        int both_cpu = task[u][2];
        for (int cpu1 = 0; cpu1 <= limit; ++cpu1) {
            for (int cpu2 = 0; cpu2 <= limit; ++cpu2) {
                for (int gpu = 0; gpu <= limit; ++gpu) {
                    int value = prev[id(cpu1, cpu2, gpu)];
                    if (value >= INF) {
                        continue;
                    }
                    int cur_id = id(cpu1, cpu2, gpu);
                    cur[cur_id] = min(cur[cur_id], value + both_cpu);
                    if (cpu1 + one_cpu <= limit) {
                        cur[id(cpu1 + one_cpu, cpu2, gpu)] = min(cur[id(cpu1 + one_cpu, cpu2, gpu)], value);
                    }
                    if (cpu2 + one_cpu <= limit) {
                        cur[id(cpu1, cpu2 + one_cpu, gpu)] = min(cur[id(cpu1, cpu2 + one_cpu, gpu)], value);
                    }
                    if (cpu1 + cpu_gpu <= limit && gpu + cpu_gpu <= limit) {
                        cur[id(cpu1 + cpu_gpu, cpu2, gpu + cpu_gpu)] =
                            min(cur[id(cpu1 + cpu_gpu, cpu2, gpu + cpu_gpu)], value);
                    }
                    if (cpu2 + cpu_gpu <= limit && gpu + cpu_gpu <= limit) {
                        cur[id(cpu1, cpu2 + cpu_gpu, gpu + cpu_gpu)] =
                            min(cur[id(cpu1, cpu2 + cpu_gpu, gpu + cpu_gpu)], value);
                    }
                }
            }
        }
        prev.swap(cur);
    }

    int ans = INF;
    for (int cpu1 = 0; cpu1 <= limit; ++cpu1) {
        for (int cpu2 = 0; cpu2 <= limit; ++cpu2) {
            for (int gpu = 0; gpu <= limit; ++gpu) {
                int value = prev[id(cpu1, cpu2, gpu)];
                if (value >= INF) {
                    continue;
                }
                ans = min(ans, value + max({cpu1, cpu2, gpu}));
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

