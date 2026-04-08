#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int inf = amount + 1;
        vector<int> dp(amount + 1, inf);
        dp[0] = 0;

        for (int coin : coins) {
            if (coin <= 0) {
                continue;
            }

            for (int cur = coin; cur <= amount; cur++) {
                dp[cur] = min(dp[cur], dp[cur - coin] + 1);
            }
        }

        return dp[amount] == inf ? -1 : dp[amount];
    }
};

vector<int> parseCoins(const string& line) {
    string cleaned = line;
    for (char& ch : cleaned) {
        if (!(isdigit(static_cast<unsigned char>(ch)) || ch == '-')) {
            ch = ' ';
        }
    }

    stringstream ss(cleaned);
    vector<int> coins;
    int x = 0;
    while (ss >> x) {
        coins.push_back(x);
    }
    return coins;
}

int main() {
    string line;
    getline(cin >> ws, line);
    vector<int> coins = parseCoins(line);

    int amount = 0;
    cin >> amount;

    Solution s;
    cout << s.coinChange(coins, amount) << endl;
}
