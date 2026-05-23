#include <bits/stdc++.h>
using namespace std;

int eval_expr(const string& s) {
    vector<int> nums;
    vector<char> ops;
    nums.push_back(s[0] - '0');

    for (int i = 1; i < (int)s.size(); i += 2) {
        char op = s[i];
        int value = s[i + 1] - '0';
        if (op == 'x') {
            nums.back() *= value;
        } else if (op == '/') {
            nums.back() /= value;
        } else {
            ops.push_back(op);
            nums.push_back(value);
        }
    }

    int result = nums[0];
    for (int i = 0; i < (int)ops.size(); ++i) {
        if (ops[i] == '+') result += nums[i + 1];
        else result -= nums[i + 1];
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        string expr;
        cin >> expr;
        cout << (eval_expr(expr) == 24 ? "Yes" : "No") << '\n';
    }

    return 0;
}
