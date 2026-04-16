#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<long long> nums;
    stack<char> ops;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        nums.push(x);
    }

    for (int i = 0; i < n - 1; i++) {
        char op;
        cin >> op;
        ops.push(op);
    }

    while (!ops.empty()) {
        long long n1 = nums.top();
        nums.pop();
        long long n2 = nums.top();
        nums.pop();

        char op = ops.top();
        ops.pop();

        long long ans = 0;
        if (op == '+') {
            ans = n2 + n1;
        } else if (op == '-') {
            ans = n2 - n1;
        } else if (op == '*') {
            ans = n2 * n1;
        } else if (op == '/') {
            if (n1 == 0) {
                cout << "ERROR: " << n2 << "/0" << endl;
                return 0;
            }
            ans = n2 / n1;
        }

        nums.push(ans);
    }

    cout << nums.top() << endl;
    return 0;
}
