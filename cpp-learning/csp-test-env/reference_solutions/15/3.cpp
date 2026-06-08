#include <bits/stdc++.h>
using namespace std;

struct Prefix {
    uint32_t ip;
    int len;
};

uint32_t mask_len(int len) {
    if (len == 0) return 0;
    return (uint32_t)(0xFFFFFFFFu << (32 - len));
}

uint32_t parse_ip(vector<int> parts) {
    while (parts.size() < 4) parts.push_back(0);
    uint32_t ip = 0;
    for (int value : parts) {
        ip = (ip << 8) | (uint32_t)value;
    }
    return ip;
}

Prefix parse_prefix(const string& s) {
    string addr = s;
    int len = -1;
    size_t slash = s.find('/');
    if (slash != string::npos) {
        addr = s.substr(0, slash);
        len = stoi(s.substr(slash + 1));
    }
    vector<int> parts;
    string cur;
    for (char c : addr) {
        if (c == '.') {
            parts.push_back(stoi(cur));
            cur.clear();
        } else {
            cur.push_back(c);
        }
    }
    parts.push_back(stoi(cur));
    if (len == -1) len = (int)parts.size() * 8;
    uint32_t ip = parse_ip(parts) & mask_len(len);
    return {ip, len};
}

bool covers(const Prefix& a, const Prefix& b) {
    return a.len <= b.len && (b.ip & mask_len(a.len)) == a.ip;
}

bool can_merge(const Prefix& a, const Prefix& b, Prefix& parent) {
    if (a.len != b.len || a.len == 0) return false;
    uint64_t block = 1ull << (32 - a.len);
    if ((uint64_t)a.ip + block != b.ip) return false;
    int parent_len = a.len - 1;
    uint32_t parent_ip = a.ip & mask_len(parent_len);
    if ((a.ip & mask_len(parent_len)) != (b.ip & mask_len(parent_len))) return false;
    if ((uint64_t)parent_ip + (1ull << (32 - parent_len)) != (uint64_t)b.ip + block) return false;
    parent = {parent_ip, parent_len};
    return true;
}

string ip_to_string(uint32_t ip) {
    return to_string((ip >> 24) & 255) + "." + to_string((ip >> 16) & 255) + "." +
           to_string((ip >> 8) & 255) + "." + to_string(ip & 255);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Prefix> input(n);
    for (Prefix& p : input) {
        string s;
        cin >> s;
        p = parse_prefix(s);
    }

    sort(input.begin(), input.end(), [](const Prefix& a, const Prefix& b) {
        return a.ip != b.ip ? a.ip < b.ip : a.len < b.len;
    });

    vector<Prefix> filtered;
    for (const Prefix& p : input) {
        if (!filtered.empty() && covers(filtered.back(), p)) {
            continue;
        }
        filtered.push_back(p);
    }

    vector<Prefix> st;
    for (Prefix p : filtered) {
        st.push_back(p);
        while (st.size() >= 2) {
            Prefix parent;
            Prefix b = st.back();
            Prefix a = st[st.size() - 2];
            if (!can_merge(a, b, parent)) break;
            st.pop_back();
            st.pop_back();
            st.push_back(parent);
            while (st.size() >= 2 && covers(st[st.size() - 2], st.back())) {
                st.pop_back();
            }
        }
    }

    sort(st.begin(), st.end(), [](const Prefix& a, const Prefix& b) {
        return a.ip != b.ip ? a.ip < b.ip : a.len < b.len;
    });
    for (const Prefix& p : st) {
        cout << ip_to_string(p.ip) << '/' << p.len << '\n';
    }
    return 0;
}
