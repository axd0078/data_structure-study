#include <bits/stdc++.h>
using namespace std;

struct Order {
    string side;
    int price;
    long long amount;
};

int parse_price(const string& s) {
    int dot = (int)s.find('.');
    int whole = stoi(s.substr(0, dot));
    int cents = stoi(s.substr(dot + 1));
    return whole * 100 + cents;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<string>> records;
    string op;
    while (cin >> op) {
        if (op == "cancel") {
            string index;
            cin >> index;
            records.push_back({op, index});
        } else {
            string price, amount;
            cin >> price >> amount;
            records.push_back({op, price, amount});
        }
    }

    vector<int> canceled(records.size());
    for (int i = 0; i < (int)records.size(); ++i) {
        if (records[i][0] == "cancel") {
            int target = stoi(records[i][1]) - 1;
            if (0 <= target && target < (int)records.size()) {
                canceled[target] = true;
            }
            canceled[i] = true;
        }
    }

    map<int, long long> buy_at_price;
    map<int, long long> sell_at_price;
    set<int> prices;
    for (int i = 0; i < (int)records.size(); ++i) {
        if (canceled[i] || records[i][0] == "cancel") {
            continue;
        }
        Order order{records[i][0], parse_price(records[i][1]), stoll(records[i][2])};
        if (order.side == "buy") {
            buy_at_price[order.price] += order.amount;
        } else {
            sell_at_price[order.price] += order.amount;
        }
        prices.insert(order.price);
    }

    int best_price = 0;
    long long best_volume = 0;
    map<int, long long> buy_ge;
    long long buy_sum = 0;
    for (auto it = prices.rbegin(); it != prices.rend(); ++it) {
        buy_sum += buy_at_price[*it];
        buy_ge[*it] = buy_sum;
    }

    long long sell_sum = 0;
    for (int price : prices) {
        sell_sum += sell_at_price[price];
        long long volume = min(buy_ge[price], sell_sum);
        if (volume > best_volume || (volume == best_volume && price > best_price)) {
            best_volume = volume;
            best_price = price;
        }
    }
    cout << best_price / 100 << '.' << setw(2) << setfill('0') << best_price % 100 << ' ' << best_volume << '\n';
    return 0;
}
