#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        string password;
        cin >> password;

        bool has_letter = false;
        bool has_digit = false;
        bool has_special = false;
        array<int, 256> count{};

        for (char raw : password) {
            unsigned char ch = static_cast<unsigned char>(raw);
            if (isalpha(ch)) {
                has_letter = true;
            }
            if (isdigit(ch)) {
                has_digit = true;
            }
            if (raw == '*' || raw == '#') {
                has_special = true;
            }
            ++count[ch];
        }

        if (!(has_letter && has_digit && has_special)) {
            cout << 0 << '\n';
            continue;
        }

        bool high = true;
        for (int amount : count) {
            if (amount > 2) {
                high = false;
                break;
            }
        }
        cout << (high ? 2 : 1) << '\n';
    }

    return 0;
}
