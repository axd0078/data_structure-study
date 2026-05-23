#include <bits/stdc++.h>
using namespace std;

const unsigned long long HASH_MULT = 47055833459ULL;

int char_to_value(char c) {
    if (c == ' ') return 0;
    if ('0' <= c && c <= '9') return c - '0' + 1;
    if ('A' <= c && c <= 'Z') return c - 'A' + 11;
    return 37;
}

char value_to_char(int value) {
    if (value == 0) return ' ';
    if (1 <= value && value <= 10) return char('0' + value - 1);
    if (11 <= value && value <= 36) return char('A' + value - 11);
    return '_';
}

unsigned long long normal_value(string code) {
    while (code.size() < 11) {
        code.push_back(' ');
    }
    unsigned long long value = 0;
    for (char c : code) {
        value = value * 38 + char_to_value(c);
    }
    return value;
}

string decode_normal(unsigned long long value) {
    string code(11, ' ');
    for (int i = 10; i >= 0; --i) {
        code[i] = value_to_char(value % 38);
        value /= 38;
    }
    while (!code.empty() && code.back() == ' ') {
        code.pop_back();
    }
    return code;
}

string decode_typical(unsigned long long value) {
    unsigned long long x = value - (1ULL << 25);
    int c6 = x % 26; x /= 26;
    int c5 = x % 26; x /= 26;
    int c4 = x % 26; x /= 26;
    int c3 = x % 10; x /= 10;
    int c2 = x % 36; x /= 36;
    int c1 = x;

    string code;
    if (c1 != 0) {
        code.push_back(value_to_char(c1));
    }
    code.push_back(c2 < 10 ? char('0' + c2) : char('A' + c2 - 10));
    code.push_back(char('0' + c3));
    code.push_back(char('A' + c4));
    code.push_back(char('A' + c5));
    code.push_back(char('A' + c6));
    return code;
}

unsigned long long code_hash(const string& code, int bits) {
    unsigned long long product = normal_value(code) * HASH_MULT;
    return product >> (64 - bits);
}

unsigned long long read_bits(const string& bits, int start, int length) {
    unsigned long long value = 0;
    for (int i = start; i < start + length; ++i) {
        value = value * 2 + (bits[i] - '0');
    }
    return value;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<unsigned long long, string> hash12;
    unordered_map<unsigned long long, string> hash25;

    auto add_code = [&](const string& code) {
        hash12[code_hash(code, 12)] = code;
        hash25[code_hash(code, 25)] = code;
    };

    auto decode_simple = [&](unsigned long long value) {
        if (value >= (1ULL << 25)) {
            return decode_typical(value);
        }
        auto it = hash25.find(value);
        if (it != hash25.end()) {
            return string("#") + it->second;
        }
        return string("###");
    };

    int n;
    cin >> n;
    while (n--) {
        string message;
        cin >> message;
        if (message[0] == '0') {
            unsigned long long receiver_value = read_bits(message, 1, 28);
            unsigned long long sender_value = read_bits(message, 29, 28);
            unsigned long long position = read_bits(message, 57, 15);
            string receiver = decode_simple(receiver_value);
            string sender = decode_simple(sender_value);

            cout << receiver << ' ' << sender;
            if (position != 0) {
                cout << ' ' << position;
            }
            cout << '\n';

            if (receiver_value >= (1ULL << 25)) {
                add_code(receiver);
            }
            if (sender_value >= (1ULL << 25)) {
                add_code(sender);
            }
        } else {
            string full_code = decode_normal(read_bits(message, 1, 58));
            unsigned long long other_hash = read_bits(message, 59, 12);
            int flag = message[71] - '0';
            auto it = hash12.find(other_hash);
            string other_code = (it == hash12.end()) ? "###" : string("#") + it->second;
            if (flag == 0) {
                cout << other_code << ' ' << full_code << '\n';
            } else {
                cout << full_code << ' ' << other_code << '\n';
            }
            add_code(full_code);
        }
    }
    return 0;
}
