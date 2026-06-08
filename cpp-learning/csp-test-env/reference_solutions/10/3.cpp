#include <bits/stdc++.h>
using namespace std;

string render_inline(const string& s, int left, int right) {
    string out;
    for (int i = left; i < right;) {
        if (s[i] == '_') {
            int j = i + 1;
            while (j < right && s[j] != '_') ++j;
            out += "<em>" + render_inline(s, i + 1, j) + "</em>";
            i = j + 1;
        } else if (s[i] == '[') {
            int mid = i + 1;
            while (mid < right && s[mid] != ']') ++mid;
            int url_left = mid + 2;
            int url_right = url_left;
            while (url_right < right && s[url_right] != ')') ++url_right;
            out += "<a href=\"" + s.substr(url_left, url_right - url_left) + "\">";
            out += render_inline(s, i + 1, mid);
            out += "</a>";
            i = url_right + 1;
        } else {
            out.push_back(s[i]);
            ++i;
        }
    }
    return out;
}

string render_inline(const string& s) {
    return render_inline(s, 0, (int)s.size());
}

bool is_heading(const string& line) {
    int cnt = 0;
    while (cnt < (int)line.size() && line[cnt] == '#') ++cnt;
    return 1 <= cnt && cnt <= 6 && cnt < (int)line.size() && line[cnt] == ' ';
}

bool is_list_item(const string& line) {
    return line.size() >= 2 && line[0] == '*' && line[1] == ' ';
}

string remove_marker_spaces(const string& line, int pos) {
    while (pos < (int)line.size() && line[pos] == ' ') ++pos;
    return line.substr(pos);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> lines;
    string line;
    while (getline(cin, line)) {
        lines.push_back(line);
    }

    for (int i = 0; i < (int)lines.size();) {
        while (i < (int)lines.size() && lines[i].empty()) ++i;
        if (i == (int)lines.size()) break;

        if (is_heading(lines[i])) {
            int level = 0;
            while (lines[i][level] == '#') ++level;
            string content = remove_marker_spaces(lines[i], level);
            cout << "<h" << level << ">" << render_inline(content) << "</h" << level << ">\n";
            ++i;
        } else if (is_list_item(lines[i])) {
            cout << "<ul>\n";
            while (i < (int)lines.size() && is_list_item(lines[i])) {
                cout << "<li>" << render_inline(remove_marker_spaces(lines[i], 1)) << "</li>\n";
                ++i;
            }
            cout << "</ul>\n";
        } else {
            string paragraph;
            while (i < (int)lines.size() && !lines[i].empty() && !is_heading(lines[i]) && !is_list_item(lines[i])) {
                if (!paragraph.empty()) paragraph.push_back('\n');
                paragraph += lines[i];
                ++i;
            }
            cout << "<p>" << render_inline(paragraph) << "</p>\n";
        }
    }
    return 0;
}
