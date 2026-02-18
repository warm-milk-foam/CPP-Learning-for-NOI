#include <bits/stdc++.h>
using namespace std;
//https://codebreaker.xyz/problem/omnomnom 
// ai solution

static const int MAXN = 100000;

vector<int> adj[MAXN + 1];
int dp[MAXN + 1][2];   // dp[u][0] = u not taken, dp[u][1] = u taken

void dfs(int u, int parent) {
    dp[u][1] = 1;   // take this node
    dp[u][0] = 0;   // do not take this node

    for (int v : adj[u]) {
        if (v == parent) continue;

        dfs(v, u);

        // If u is taken, children cannot be taken
        dp[u][1] += dp[v][0];

        // If u is not taken, children can be taken or not
        dp[u][0] += max(dp[v][0], dp[v][1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Root the tree at node 1
    dfs(1, 0);

    // Answer is best of taking or not taking the root
    cout << max(dp[1][0], dp[1][1]) << "\n";
    return 0;
}
