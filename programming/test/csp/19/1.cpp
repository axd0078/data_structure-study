#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x;
    long long y;
    char type;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Point> points(n);
    for (auto &point : points) {
        cin >> point.x >> point.y >> point.type;
    }
    while (m--) {
        int signA = 0,signB = 0;
        bool ok = true;
        long long t0,t1,t2;
        cin >> t0 >> t1 >> t2;
        for(const Point& p:points){
            long long value = t0 + t1*p.x + t2*p.y;
            int sign = value>0 ? 1 : -1;
            int& temp = p.type == 'A' ? signA : signB;
            if(temp == 0) temp = sign;
            else if(temp!=sign){
                    ok = false;
                    break;
                }
        }
        cout << (ok && signA != signB ? "Yes" : "No") << endl;
    }

    return 0;
}
