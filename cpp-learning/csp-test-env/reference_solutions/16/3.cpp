#include <bits/stdc++.h>
using namespace std;

uint32_t parse_block(const string& s, int pos) {
    uint32_t value = 0;
    for (int i = 0; i < 8; ++i) {
        char c = s[pos + i];
        int digit = isdigit((unsigned char)c) ? c - '0' : c - 'A' + 10;
        value = (value << 4) | (uint32_t)digit;
    }
    return value;
}

string hex_block(uint32_t value) {
    const char* hex = "0123456789ABCDEF";
    string out(8, '0');
    for (int i = 7; i >= 0; --i) {
        out[i] = hex[value & 15];
        value >>= 4;
    }
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s, l;
    cin >> n >> s >> l;
    vector<vector<uint32_t>> disk(n);
    int blocks_per_disk = -1;
    for (int i = 0; i < l; ++i) {
        int id;
        string data;
        cin >> id >> data;
        blocks_per_disk = (int)data.size() / 8;
        disk[id].resize(blocks_per_disk);
        for (int j = 0; j < blocks_per_disk; ++j) {
            disk[id][j] = parse_block(data, j * 8);
        }
    }

    int m;
    cin >> m;
    while (m--) {
        long long b;
        cin >> b;
        long long total_blocks = 1LL * blocks_per_disk * (n - 1);
        if (blocks_per_disk < 0 || b < 0 || b >= total_blocks) {
            cout << "-\n";
            continue;
        }

        long long data_strip = b / s;
        int offset = (int)(b % s);
        long long row = data_strip / (n - 1);
        int data_index = (int)(data_strip % (n - 1));
        int parity = (n - 1 - (int)(row % n) + n) % n;
        int disk_id = (parity + 1 + data_index) % n;
        int physical = (int)(row * s + offset);

        if (!disk[disk_id].empty()) {
            cout << hex_block(disk[disk_id][physical]) << '\n';
        } else if (l == n - 1) {
            uint32_t value = 0;
            bool ok = true;
            for (int id = 0; id < n; ++id) {
                if (id == disk_id) continue;
                if (disk[id].empty() || physical >= (int)disk[id].size()) {
                    ok = false;
                    break;
                }
                value ^= disk[id][physical];
            }
            cout << (ok ? hex_block(value) : "-") << '\n';
        } else {
            cout << "-\n";
        }
    }
    return 0;
}
