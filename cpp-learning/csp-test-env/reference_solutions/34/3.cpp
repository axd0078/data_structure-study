#include <bits/stdc++.h>
using namespace std;

struct Word {
    vector<string> pieces;
    long long freq;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Word> words;
    set<char> letters;
    for (int i = 0; i < n; i++) {
        string s;
        long long f;
        cin >> s >> f;
        vector<string> pieces;
        for (char ch : s) {
            letters.insert(ch);
            pieces.push_back(string(1, ch));
        }
        words.push_back({pieces, f});
    }

    vector<string> vocab;
    for (char ch : letters) {
        vocab.push_back(string(1, ch));
    }

    while ((int)vocab.size() < m) {
        map<pair<string, string>, long long> counts;
        for (const auto& word : words) {
            for (int i = 0; i + 1 < (int)word.pieces.size(); i++) {
                counts[{word.pieces[i], word.pieces[i + 1]}] += word.freq;
            }
        }
        if (counts.empty()) {
            break;
        }

        pair<string, string> best;
        bool has_best = false;
        for (const auto& [pair_value, freq] : counts) {
            if (!has_best) {
                best = pair_value;
                has_best = true;
                continue;
            }
            string cur_joined = pair_value.first + pair_value.second;
            string best_joined = best.first + best.second;
            long long best_freq = counts[best];
            if (freq > best_freq ||
                (freq == best_freq &&
                 (cur_joined.size() < best_joined.size() ||
                  (cur_joined.size() == best_joined.size() &&
                   (pair_value.first.size() < best.first.size() ||
                    (pair_value.first.size() == best.first.size() && cur_joined < best_joined)))))) {
                best = pair_value;
            }
        }

        string merged = best.first + best.second;
        vocab.push_back(merged);

        for (auto& word : words) {
            vector<string> next;
            for (int i = 0; i < (int)word.pieces.size();) {
                if (i + 1 < (int)word.pieces.size() && word.pieces[i] == best.first && word.pieces[i + 1] == best.second) {
                    next.push_back(merged);
                    i += 2;
                } else {
                    next.push_back(word.pieces[i]);
                    i++;
                }
            }
            word.pieces = move(next);
        }
    }

    for (const string& token : vocab) {
        cout << token << '\n';
    }

    return 0;
}
