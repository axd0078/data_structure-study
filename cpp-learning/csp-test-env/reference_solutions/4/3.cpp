#include <bits/stdc++.h>
using namespace std;

bool leap(int year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

int days_in_month(int year, int month) {
    static int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && leap(year)) {
        return 29;
    }
    return days[month];
}

int weekday_of_first_day(int year, int month) {
    int weekday = 2; // 1850/01/01 is Tuesday. Monday=1, ..., Sunday=7.
    for (int y = 1850; y < year; ++y) {
        weekday = (weekday + (leap(y) ? 366 : 365)) % 7;
        if (weekday == 0) {
            weekday = 7;
        }
    }
    for (int m = 1; m < month; ++m) {
        weekday = (weekday + days_in_month(year, m)) % 7;
        if (weekday == 0) {
            weekday = 7;
        }
    }
    return weekday;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int month, nth, weekday, y1, y2;
    cin >> month >> nth >> weekday >> y1 >> y2;

    for (int year = y1; year <= y2; ++year) {
        int first = weekday_of_first_day(year, month);
        int day = 1 + (weekday - first + 7) % 7 + (nth - 1) * 7;
        if (day > days_in_month(year, month)) {
            cout << "none\n";
        } else {
            cout << setw(4) << setfill('0') << year << '/'
                 << setw(2) << setfill('0') << month << '/'
                 << setw(2) << setfill('0') << day << '\n';
        }
    }
    return 0;
}
