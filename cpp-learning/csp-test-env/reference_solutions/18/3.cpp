#include <bits/stdc++.h>
using namespace std;

using Counter = map<string, long long>;

struct Parser {
    string s;
    int pos = 0;

    long long parse_number() {
        if (pos >= (int)s.size() || !isdigit((unsigned char)s[pos])) return 1;
        long long value = 0;
        while (pos < (int)s.size() && isdigit((unsigned char)s[pos])) {
            value = value * 10 + (s[pos++] - '0');
        }
        return value;
    }

    Counter parse_formula() {
        Counter result;
        while (pos < (int)s.size() && s[pos] != ')' && s[pos] != '+' && s[pos] != '=') {
            Counter term;
            if (s[pos] == '(') {
                ++pos;
                term = parse_formula();
                ++pos;
            } else {
                string element;
                element.push_back(s[pos++]);
                if (pos < (int)s.size() && islower((unsigned char)s[pos])) {
                    element.push_back(s[pos++]);
                }
                term[element] = 1;
            }
            long long coef = parse_number();
            for (auto [element, count] : term) {
                result[element] += count * coef;
            }
        }
        return result;
    }
};

Counter parse_expr(const string& expr) {
    Counter total;
    int pos = 0;
    while (pos < (int)expr.size()) {
        int start = pos;
        while (pos < (int)expr.size() && isdigit((unsigned char)expr[pos])) ++pos;
        long long coef = 1;
        if (start != pos) coef = stoll(expr.substr(start, pos - start));
        int formula_start = pos;
        int depth = 0;
        while (pos < (int)expr.size()) {
            if (expr[pos] == '(') ++depth;
            else if (expr[pos] == ')') --depth;
            else if (expr[pos] == '+' && depth == 0) break;
            ++pos;
        }
        Parser parser{expr.substr(formula_start, pos - formula_start), 0};
        Counter one = parser.parse_formula();
        for (auto [element, count] : one) {
            total[element] += count * coef;
        }
        if (pos < (int)expr.size() && expr[pos] == '+') ++pos;
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        string equation;
        cin >> equation;
        size_t eq = equation.find('=');
        Counter left = parse_expr(equation.substr(0, eq));
        Counter right = parse_expr(equation.substr(eq + 1));
        cout << (left == right ? 'Y' : 'N') << '\n';
    }
    return 0;
}
