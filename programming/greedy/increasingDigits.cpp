#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string strN = to_string(n);
        int i = 1;
        int len = strN.length();

        while (i < len && strN[i - 1] <= strN[i]) {
            i++;
        }

        if (i < len) {
            // 从当前位置向左回退，找到需要减 1 的那一位。
            while (i > 0 && strN[i - 1] > strN[i]) {
                strN[i - 1]--;
                i--;
            }

            // 后面的数字全部改成 9，这样结果最大且仍满足单调递增。
            for (i = i + 1; i < len; i++) {
                strN[i] = '9';
            }
        }
        return stoi(strN);
    }
};

int main() {
    int n;
    cin >> n;

    Solution s;
    cout << s.monotoneIncreasingDigits(n) << endl;
    return 0;
}

