#include <bits/stdc++.h>
using namespace std;

struct Segment {
    int u;
    int v;
    int plan;
};

int n, station_count;
vector<vector<int>> graph_adj;
vector<pair<int, int>> edges;
vector<int> depth_value;
vector<array<int, 18>> up;
vector<int> dsu_parent;
vector<int> dsu_size;
vector<unordered_set<int>> contracted_adj;
vector<unordered_map<int, vector<int>>> requests;
vector<Segment> segments;
vector<int> remaining_segments;
vector<char> segment_done;
long long feasible_plans = 0;

int find_root(int x) {
    while (dsu_parent[x] != x) {
        dsu_parent[x] = dsu_parent[dsu_parent[x]];
        x = dsu_parent[x];
    }
    return x;
}

long long edge_key(int u, int v) {
    if (u > v) {
        swap(u, v);
    }
    return 1LL * u * (n + 1) + v;
}

void dfs_lca(int root) {
    vector<int> parent(n + 1, 0);
    vector<int> order;
    order.reserve(n);
    order.push_back(root);
    parent[root] = root;
    for (size_t i = 0; i < order.size(); ++i) {
        int u = order[i];
        up[u][0] = parent[u];
        for (int j = 1; j < 18; ++j) {
            up[u][j] = up[up[u][j - 1]][j - 1];
        }
        for (int v : graph_adj[u]) {
            if (v == parent[u]) {
                continue;
            }
            parent[v] = u;
            depth_value[v] = depth_value[u] + 1;
            order.push_back(v);
        }
    }
}

int lca(int a, int b) {
    if (depth_value[a] < depth_value[b]) {
        swap(a, b);
    }
    int diff = depth_value[a] - depth_value[b];
    for (int j = 0; j < 18; ++j) {
        if (diff & (1 << j)) {
            a = up[a][j];
        }
    }
    if (a == b) {
        return a;
    }
    for (int j = 17; j >= 0; --j) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

int distance_on_tree(int a, int b) {
    int c = lca(a, b);
    return depth_value[a] + depth_value[b] - 2 * depth_value[c];
}

bool on_path(int s, int t, int x) {
    return distance_on_tree(s, x) + distance_on_tree(x, t) == distance_on_tree(s, t);
}

bool adjacent_components(int a, int b) {
    a = find_root(a);
    b = find_root(b);
    if (a == b) {
        return true;
    }
    if (contracted_adj[a].size() > contracted_adj[b].size()) {
        swap(a, b);
    }
    return contracted_adj[a].find(b) != contracted_adj[a].end();
}

void mark_segment_done(int id) {
    if (segment_done[id]) {
        return;
    }
    segment_done[id] = 1;
    int plan = segments[id].plan;
    --remaining_segments[plan];
    if (remaining_segments[plan] == 0) {
        ++feasible_plans;
    }
}

void activate_pair(int a, int b) {
    a = find_root(a);
    b = find_root(b);
    if (a == b) {
        auto it_same = requests[a].find(b);
        if (it_same != requests[a].end()) {
            for (int id : it_same->second) {
                mark_segment_done(id);
            }
            requests[a].erase(it_same);
        }
        return;
    }

    auto it = requests[a].find(b);
    if (it != requests[a].end()) {
        for (int id : it->second) {
            mark_segment_done(id);
        }
        requests[a].erase(it);
    }
    auto rev = requests[b].find(a);
    if (rev != requests[b].end()) {
        requests[b].erase(rev);
    }
}

void activate_side_against_neighbors(int side, int other) {
    side = find_root(side);
    other = find_root(other);
    vector<int> to_activate;
    if (requests[side].size() <= contracted_adj[other].size()) {
        to_activate.reserve(requests[side].size());
        for (const auto& [target, ids] : requests[side]) {
            if (target != other && contracted_adj[other].find(target) != contracted_adj[other].end()) {
                to_activate.push_back(target);
            }
        }
    } else {
        to_activate.reserve(contracted_adj[other].size());
        for (int neighbor : contracted_adj[other]) {
            if (neighbor != side && requests[side].find(neighbor) != requests[side].end()) {
                to_activate.push_back(neighbor);
            }
        }
    }
    for (int target : to_activate) {
        activate_pair(side, target);
    }
}

void merge_request_maps(int winner, int loser) {
    vector<pair<int, vector<int>>> moved;
    moved.reserve(requests[loser].size());
    for (auto& entry : requests[loser]) {
        moved.push_back({entry.first, move(entry.second)});
    }
    requests[loser].clear();

    for (auto& [target, ids] : moved) {
        target = find_root(target);
        if (target == winner || adjacent_components(winner, target)) {
            for (int id : ids) {
                mark_segment_done(id);
            }
            auto rev = requests[target].find(loser);
            if (rev != requests[target].end()) {
                requests[target].erase(rev);
            }
            rev = requests[target].find(winner);
            if (rev != requests[target].end()) {
                requests[target].erase(rev);
            }
            continue;
        }

        auto rev = requests[target].find(loser);
        if (rev != requests[target].end()) {
            auto& dest = requests[target][winner];
            dest.insert(dest.end(), rev->second.begin(), rev->second.end());
            requests[target].erase(rev);
        }

        auto& dest = requests[winner][target];
        dest.insert(dest.end(), ids.begin(), ids.end());
    }
}

void repair_edge(int u, int v) {
    int a = find_root(u);
    int b = find_root(v);
    if (a == b) {
        return;
    }

    activate_pair(a, b);
    activate_side_against_neighbors(a, b);
    activate_side_against_neighbors(b, a);

    long long weight_a = (long long)contracted_adj[a].size() + (long long)requests[a].size() + dsu_size[a];
    long long weight_b = (long long)contracted_adj[b].size() + (long long)requests[b].size() + dsu_size[b];
    int winner = a;
    int loser = b;
    if (weight_a < weight_b) {
        winner = b;
        loser = a;
    }

    dsu_parent[loser] = winner;
    dsu_size[winner] += dsu_size[loser];

    vector<int> neighbors;
    neighbors.reserve(contracted_adj[loser].size());
    for (int neighbor : contracted_adj[loser]) {
        neighbors.push_back(neighbor);
    }
    contracted_adj[loser].clear();
    contracted_adj[winner].erase(loser);
    for (int neighbor : neighbors) {
        if (neighbor == winner) {
            continue;
        }
        contracted_adj[neighbor].erase(loser);
        contracted_adj[neighbor].insert(winner);
        contracted_adj[winner].insert(neighbor);
    }
    contracted_adj[winner].erase(winner);

    merge_request_maps(winner, loser);
}

void add_segment_condition(int u, int v, int plan_id) {
    int id = (int)segments.size();
    segments.push_back({u, v, plan_id});
    segment_done.push_back(0);
    if (distance_on_tree(u, v) <= 1) {
        segment_done[id] = 1;
        return;
    }
    ++remaining_segments[plan_id];
    requests[u][v].push_back(id);
    requests[v][u].push_back(id);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int online_x;
    cin >> n >> online_x;
    graph_adj.assign(n + 1, {});
    edges.assign(n, {0, 0});
    unordered_map<long long, int> edge_id;
    edge_id.reserve(n * 2);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
        graph_adj[u].push_back(v);
        graph_adj[v].push_back(u);
        edge_id[edge_key(u, v)] = i;
    }

    cin >> station_count;
    vector<int> stations(station_count);
    for (int i = 0; i < station_count; ++i) {
        cin >> stations[i];
    }

    depth_value.assign(n + 1, 0);
    up.assign(n + 1, {});
    dfs_lca(1);

    int plan_count;
    cin >> plan_count;
    vector<pair<int, int>> plans(plan_count);
    remaining_segments.assign(plan_count, 0);

    dsu_parent.resize(n + 1);
    dsu_size.assign(n + 1, 1);
    contracted_adj.assign(n + 1, {});
    requests.assign(n + 1, {});
    for (int i = 1; i <= n; ++i) {
        dsu_parent[i] = i;
    }
    for (int i = 1; i < n; ++i) {
        auto [u, v] = edges[i];
        contracted_adj[u].insert(v);
        contracted_adj[v].insert(u);
    }

    segments.reserve((size_t)plan_count * (station_count + 1));
    segment_done.reserve((size_t)plan_count * (station_count + 1));

    for (int i = 0; i < plan_count; ++i) {
        int s, t;
        cin >> s >> t;
        plans[i] = {s, t};
        vector<pair<int, int>> path_stations;
        path_stations.reserve(station_count);
        for (int station : stations) {
            if (on_path(s, t, station)) {
                path_stations.push_back({distance_on_tree(s, station), station});
            }
        }
        sort(path_stations.begin(), path_stations.end());

        vector<int> anchors;
        anchors.reserve(path_stations.size() + 2);
        anchors.push_back(s);
        for (auto [dist, station] : path_stations) {
            if (anchors.back() != station) {
                anchors.push_back(station);
            }
        }
        if (anchors.back() != t) {
            anchors.push_back(t);
        }
        for (int j = 0; j + 1 < (int)anchors.size(); ++j) {
            add_segment_condition(anchors[j], anchors[j + 1], i);
        }
    }

    feasible_plans = 0;
    for (int i = 0; i < plan_count; ++i) {
        if (remaining_segments[i] == 0) {
            ++feasible_plans;
        }
    }

    int q;
    cin >> q;
    long long lastans = 0;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            long long encoded_u, encoded_v;
            cin >> encoded_u >> encoded_v;
            int u = (int)(encoded_u ^ (1LL * online_x * lastans));
            int v = (int)(encoded_v ^ (1LL * online_x * lastans));
            auto it = edge_id.find(edge_key(u, v));
            if (it != edge_id.end()) {
                repair_edge(u, v);
            }
        } else {
            cout << feasible_plans << '\n';
            lastans = feasible_plans;
        }
    }

    return 0;
}
