#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

struct Definition {
    bool direct = true;
    long long len = 0;
    vector<string> expr;
};

unordered_map<string, Definition> definitions;

long long eval_var(const string& name, unordered_map<string, long long>& memo) {
    if (memo.count(name)) {
        return memo[name];
    }
    if (!definitions.count(name)) {
        return memo[name] = 0;
    }

    const Definition& def = definitions[name];
    if (def.direct) {
        return memo[name] = def.len;
    }

    long long total = 0;
    for (const string& token : def.expr) {
        if (!token.empty() && token[0] == '$') {
            total = (total + eval_var(token.substr(1), memo)) % MOD;
        } else {
            total = (total + (long long)token.size()) % MOD;
        }
    }
    return memo[name] = total;
}

long long eval_expr(const vector<string>& expr) {
    unordered_map<string, long long> memo;
    long long total = 0;
    for (const string& token : expr) {
        if (!token.empty() && token[0] == '$') {
            total = (total + eval_var(token.substr(1), memo)) % MOD;
        } else {
            total = (total + (long long)token.size()) % MOD;
        }
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        int op;
        string name;
        cin >> op >> name;

        if (op == 1 || op == 2) {
            string rest;
            getline(cin, rest);
            stringstream ss(rest);
            vector<string> expr;
            string token;
            while (ss >> token) {
                expr.push_back(token);
            }

            Definition def;
            if (op == 1) {
                def.direct = true;
                def.len = eval_expr(expr);
            } else {
                def.direct = false;
                def.expr = move(expr);
            }
            definitions[name] = move(def);
        } else {
            unordered_map<string, long long> memo;
            cout << eval_var(name, memo) << '\n';
        }
    }

    return 0;
}
