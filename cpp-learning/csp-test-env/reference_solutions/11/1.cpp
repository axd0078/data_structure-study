#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int money;
    cin >> money;

    int paidBottles = money / 10;
    int answer = paidBottles / 5 * 7;
    paidBottles %= 5;
    answer += paidBottles / 3 * 4 + paidBottles % 3;

    cout << answer << '\n';
    return 0;
}
