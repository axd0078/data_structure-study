#include <bits/stdc++.h>
using namespace std;

vector<string> split_path(const string& path) {
    vector<string> parts;
    string cur;
    for (char ch : path) {
        if (ch == '/') {
            parts.push_back(cur);
            cur.clear();
        } else {
            cur.push_back(ch);
        }
    }
    parts.push_back(cur);
    return parts;
}

string normalize_path(const string& current, const string& path) {
    vector<string> stack;
    if (path.empty() || path[0] != '/') {
        for (const string& part : split_path(current)) {
            if (!part.empty()) {
                stack.push_back(part);
            }
        }
    }

    for (const string& part : split_path(path)) {
        if (part.empty() || part == ".") {
            continue;
        }
        if (part == "..") {
            if (!stack.empty()) {
                stack.pop_back();
            }
        } else {
            stack.push_back(part);
        }
    }

    if (stack.empty()) {
        return "/";
    }
    string result;
    for (const string& part : stack) {
        result += "/" + part;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int p;
    string current;
    cin >> p >> current;
    string path;
    getline(cin, path);
    while (p--) {
        getline(cin, path);
        cout << normalize_path(current, path) << '\n';
    }
    return 0;
}
