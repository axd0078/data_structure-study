#include <bits/stdc++.h>
using namespace std;

struct Color {
    int r, g, b;
};

Color parse_color(const string& s) {
    auto val = [](char c) {
        if (isdigit((unsigned char)c)) return c - '0';
        if ('a' <= c && c <= 'f') return c - 'a' + 10;
        return c - 'A' + 10;
    };
    if (s.size() == 2) {
        int x = val(s[1]) * 17;
        return {x, x, x};
    }
    if (s.size() == 4) {
        return {val(s[1]) * 17, val(s[2]) * 17, val(s[3]) * 17};
    }
    return {val(s[1]) * 16 + val(s[2]), val(s[3]) * 16 + val(s[4]), val(s[5]) * 16 + val(s[6])};
}

void append_bg(string& raw, Color c) {
    raw += "\033[48;2;";
    raw += to_string(c.r) + ";" + to_string(c.g) + ";" + to_string(c.b) + "m";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n, p, q;
    cin >> m >> n >> p >> q;
    vector<vector<Color>> image(n, vector<Color>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            string s;
            cin >> s;
            image[i][j] = parse_color(s);
        }
    }

    string raw;
    Color current{0, 0, 0};
    for (int br = 0; br < n; br += q) {
        for (int bc = 0; bc < m; bc += p) {
            long long sr = 0, sg = 0, sb = 0;
            for (int i = br; i < br + q; ++i) {
                for (int j = bc; j < bc + p; ++j) {
                    sr += image[i][j].r;
                    sg += image[i][j].g;
                    sb += image[i][j].b;
                }
            }
            int area = p * q;
            Color need{(int)(sr / area), (int)(sg / area), (int)(sb / area)};
            if (need.r != current.r || need.g != current.g || need.b != current.b) {
                if (need.r == 0 && need.g == 0 && need.b == 0) {
                    raw += "\033[0m";
                } else {
                    append_bg(raw, need);
                }
                current = need;
            }
            raw.push_back(' ');
        }
        if (current.r != 0 || current.g != 0 || current.b != 0) {
            raw += "\033[0m";
            current = {0, 0, 0};
        }
        raw.push_back('\n');
    }

    const char* hex = "0123456789ABCDEF";
    for (unsigned char c : raw) {
        cout << "\\x" << hex[c >> 4] << hex[c & 15];
    }
    cout << '\n';
    return 0;
}
