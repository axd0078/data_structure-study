#include <bits/stdc++.h>
using namespace std;

bool leap(int y) {
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int year, day;
    cin >> year >> day;
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (leap(year)) {
        days[2] = 29;
    }
    int month = 1;
    while (day > days[month]) {
        day -= days[month];
        ++month;
    }
    cout << month << '\n' << day << '\n';
    return 0;
}
