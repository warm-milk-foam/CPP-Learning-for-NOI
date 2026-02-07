#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e15; // define a large number for unreachable distances

// https://codebreaker.xyz/problem/mrt
int main () {
    int n, e, q;
    cin >> n >> e >> q;

    // make an adjacency list
    // a vector, of vectors containing pairs, where .first is the station and .second is the time taken
    vector<vector<pair<int, int>>> network(n);

    // distance table to store shortest times between all station pairs
    vector<vector<long long>> dist(n, vector<long long>(n, INF));

    for (int i = 0; i < n; i++) dist[i][i] = 0; // distance at same station is 0

    for (int i = 0; i < e; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        // x and y are the two stations, while z is the time taken
        network[x].push_back({y, z});
        network[y].push_back({x, z});
    }

    // because of the big number of queries, we need to precompute every node pair distance

    // run Dijkstra from each node to precompute shortest distances
    for (int start = 0; start < n; start++) {
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[start][u]) continue;

            for (auto [v, w] : network[u]) {
                if (dist[start][v] > d + w) {
                    dist[start][v] = d + w;
                    pq.push({dist[start][v], v});
                }
            }
        }
    }

    // answer queries using the precomputed distances
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == INF) cout << -1 << "\n";
        else cout << dist[a][b] << "\n";
    }

    return 0;
}
