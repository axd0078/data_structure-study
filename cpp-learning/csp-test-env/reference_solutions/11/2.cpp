#include <bits/stdc++.h>
using namespace std;

struct Event {
    int time;
    int type;
    int key;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<Event> events;
    for (int i = 0; i < k; ++i) {
        int w, s, c;
        cin >> w >> s >> c;
        events.push_back({s, 1, w});
        events.push_back({s + c, 0, w});
    }

    sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
        if (a.time != b.time) return a.time < b.time;
        if (a.type != b.type) return a.type < b.type;
        return a.key < b.key;
    });

    vector<int> box(n);
    iota(box.begin(), box.end(), 1);

    for (const auto& e : events) {
        if (e.type == 0) {
            int pos = find(box.begin(), box.end(), 0) - box.begin();
            box[pos] = e.key;
        } else {
            int pos = find(box.begin(), box.end(), e.key) - box.begin();
            box[pos] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << box[i];
    }
    cout << '\n';

    return 0;
}
