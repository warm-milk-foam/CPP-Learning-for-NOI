```
// https://codebreaker.xyz/problem/party
#include <bits/stdc++.h>
using namespace std;

int main () {
	int N, M;
	cin >> N >> M;
	
	vector<vector<int>> adj(N); // adjacency list

	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		adj[a-1].push_back(b-1); // 0-indexed
		adj[b-1].push_back(a-1); // because friendship is mutual
	}
	vector<int> visited(N, 0); // track who we have counted
    queue<pair<int,int>> q;    // {person, level}
    
    visited[0] = 1;  // yourself
    q.push({0, 0});  // start BFS at person 1, level 0
    
    int count = 0;   // number of people coming to party
    while(!q.empty()) {
        pair<int,int> p = q.front();
		int cur = p.first;
		int level = p.second;


        if(level == 2) continue; // stop after friends-of-friends

        for(int next : adj[cur]) {
            if(!visited[next]) {
                visited[next] = 1;   // mark as coming
                count++;              // include in party
                q.push({next, level + 1});
            }
        }
    }
	cout << count << "\n";
	return 0;
}
```

This is a BFS challenge where you stop searching when you reached deep enough.  
I'm not submiting this solution too because again, its cheating.  