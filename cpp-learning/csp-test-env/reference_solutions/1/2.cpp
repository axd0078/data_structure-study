#include <bits/stdc++.h>
using namespace std;

struct Window {
    int id;
    int x1;
    int y1;
    int x2;
    int y2;
};

bool contains(const Window& w, int x, int y) {
    return w.x1 <= x && x <= w.x2 && w.y1 <= y && y <= w.y2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<Window> windows;
    for (int i = 0; i < n; ++i) {
        Window w;
        w.id = i + 1;
        cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
        windows.push_back(w);
    }

    while (m--) {
        int x, y;
        cin >> x >> y;
        int hit = -1;
        for (int i = (int)windows.size() - 1; i >= 0; --i) {
            if (contains(windows[i], x, y)) {
                hit = i;
                break;
            }
        }
        if (hit == -1) {
            cout << "IGNORED\n";
        } else {
            Window w = windows[hit];
            windows.erase(windows.begin() + hit);
            windows.push_back(w);
            cout << w.id << '\n';
        }
    }
    return 0;
}

