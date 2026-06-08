#include <bits/stdc++.h>
using namespace std;

struct DateTime {
    int y, mo, d, h, mi;
};

struct Rule {
    vector<int> minute, hour, day, month, week;
    string command;
};

int month_id(const string& token) {
    static vector<string> names = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
    string s = token;
    for (char& c : s) c = (char)tolower((unsigned char)c);
    for (int i = 0; i < 12; ++i) {
        if (s == names[i]) return i + 1;
    }
    return stoi(token);
}

int week_id(const string& token) {
    static vector<string> names = {"sun", "mon", "tue", "wed", "thu", "fri", "sat"};
    string s = token;
    for (char& c : s) c = (char)tolower((unsigned char)c);
    for (int i = 0; i < 7; ++i) {
        if (s == names[i]) return i;
    }
    return stoi(token);
}

vector<string> split(const string& s, char sep) {
    vector<string> parts;
    string cur;
    for (char c : s) {
        if (c == sep) {
            parts.push_back(cur);
            cur.clear();
        } else {
            cur.push_back(c);
        }
    }
    parts.push_back(cur);
    return parts;
}

vector<int> parse_field(const string& field, int low, int high, bool is_month, bool is_week) {
    vector<int> ok(high + 1, 0);
    if (field == "*") {
        for (int i = low; i <= high; ++i) ok[i] = 1;
    } else {
        for (const string& part : split(field, ',')) {
            size_t dash = part.find('-');
            string a = dash == string::npos ? part : part.substr(0, dash);
            string b = dash == string::npos ? part : part.substr(dash + 1);
            auto conv = [&](const string& x) {
                if (is_month) return month_id(x);
                if (is_week) return week_id(x);
                return stoi(x);
            };
            int l = conv(a), r = conv(b);
            for (int i = l; i <= r; ++i) ok[i] = 1;
        }
    }
    vector<int> values;
    for (int i = low; i <= high; ++i) {
        if (ok[i]) values.push_back(i);
    }
    return values;
}

bool leap(int y) {
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

int dim(int y, int m) {
    static int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return m == 2 && leap(y) ? 29 : days[m];
}

DateTime parse_time(const string& s) {
    return {stoi(s.substr(0, 4)), stoi(s.substr(4, 2)), stoi(s.substr(6, 2)), stoi(s.substr(8, 2)), stoi(s.substr(10, 2))};
}

long long encode_time(int y, int mo, int d, int h, int mi) {
    return (((long long)y * 100 + mo) * 100 + d) * 10000 + h * 100 + mi;
}

void next_day(int& y, int& mo, int& d) {
    if (++d > dim(y, mo)) {
        d = 1;
        if (++mo > 12) {
            mo = 1;
            ++y;
        }
    }
}

int weekday(int y, int mo, int d) {
    int days = 0;
    for (int yy = 1970; yy < y; ++yy) days += leap(yy) ? 366 : 365;
    for (int mm = 1; mm < mo; ++mm) days += dim(y, mm);
    days += d - 1;
    return (4 + days) % 7;
}

bool contains(const vector<int>& values, int target) {
    return binary_search(values.begin(), values.end(), target);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string ss, tt;
    cin >> n >> ss >> tt;
    long long start_value = stoll(ss), end_value = stoll(tt);
    DateTime start = parse_time(ss), finish = parse_time(tt);
    vector<Rule> rules(n);
    for (int i = 0; i < n; ++i) {
        string a, b, c, d, e, cmd;
        cin >> a >> b >> c >> d >> e >> cmd;
        rules[i] = {parse_field(a, 0, 59, false, false),
                    parse_field(b, 0, 23, false, false),
                    parse_field(c, 1, 31, false, false),
                    parse_field(d, 1, 12, true, false),
                    parse_field(e, 0, 6, false, true),
                    cmd};
    }

    vector<tuple<long long, int, string>> events;
    int y = start.y, mo = start.mo, day = start.d;
    while (encode_time(y, mo, day, 0, 0) < encode_time(finish.y, finish.mo, finish.d, 23, 59) + 1) {
        int w = weekday(y, mo, day);
        for (int i = 0; i < n; ++i) {
            const Rule& r = rules[i];
            if (!contains(r.month, mo) || !contains(r.day, day) || !contains(r.week, w)) continue;
            for (int h : r.hour) {
                for (int mi : r.minute) {
                    long long t = encode_time(y, mo, day, h, mi);
                    if (start_value <= t && t < end_value) {
                        events.push_back({t, i, r.command});
                    }
                }
            }
        }
        if (y == finish.y && mo == finish.mo && day == finish.d) break;
        next_day(y, mo, day);
    }

    sort(events.begin(), events.end());
    for (auto [time, index, command] : events) {
        cout << setw(12) << setfill('0') << time << ' ' << command << '\n';
    }
    return 0;
}
