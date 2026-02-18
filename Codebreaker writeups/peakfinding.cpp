#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adjlist, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adjlist[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjlist, visited);
        }
    }
}

int countSubgraphs(int N, int E, vector<vector<int>>& adjlist) {
    vector<bool> visited(N, false);
    
    int subgraphCount = 0;
    
    // DFS to count connected components
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {  // Found a new component
            subgraphCount++;
            dfs(i, adjlist, visited);
        }
    }
    
    return subgraphCount;
}

int main() {
	int n, e;
    cin >> n >> e;  // Read number of nodes and edges

    vector<vector<int>> adjList(n + 1);  // Create adjacency list

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);  // Add b to a's list
        adjList[b].push_back(a);  // Add a to b's list (undirected)
    }
    cout << countSubgraphs(n, e, adjList);
}
