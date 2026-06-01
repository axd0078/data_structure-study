#include <bits/stdc++.h>
using namespace std;

struct Minion {
    int attack;
    int health;
};

struct Player {
    int hero = 30;
    vector<Minion> minions;
};

void print_minions(const vector<Minion>& minions) {
    cout << minions.size();
    for (const Minion& minion : minions) {
        cout << ' ' << minion.health;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    Player players[2];
    int current = 0;

    while (n--) {
        string action;
        cin >> action;
        if (action == "summon") {
            int position, attack, health;
            cin >> position >> attack >> health;
            auto& board = players[current].minions;
            board.insert(board.begin() + position - 1, {attack, health});
        } else if (action == "attack") {
            int attacker, defender;
            cin >> attacker >> defender;
            Minion& atk = players[current].minions[attacker - 1];
            if (defender == 0) {
                players[current ^ 1].hero -= atk.attack;
            } else {
                Minion& def = players[current ^ 1].minions[defender - 1];
                atk.health -= def.attack;
                def.health -= atk.attack;
                if (def.health <= 0) {
                    players[current ^ 1].minions.erase(players[current ^ 1].minions.begin() + defender - 1);
                }
                if (atk.health <= 0) {
                    players[current].minions.erase(players[current].minions.begin() + attacker - 1);
                }
            }
        } else {
            current ^= 1;
        }
    }

    int result = 0;
    if (players[1].hero <= 0) {
        result = 1;
    } else if (players[0].hero <= 0) {
        result = -1;
    }

    cout << result << '\n';
    cout << players[0].hero << '\n';
    print_minions(players[0].minions);
    cout << players[1].hero << '\n';
    print_minions(players[1].minions);
    return 0;
}
