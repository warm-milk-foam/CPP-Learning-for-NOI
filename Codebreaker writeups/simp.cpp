// The boiler starter code I should always use.
// https://codebreaker.xyz/problem/simp
// this has a LOT of help from chatgpt, but i tried to write as much as possible, my own code.
// https://chatgpt.com/share/69903fdc-dbe0-8000-a665-fd223a38570d
#include <bits/stdc++.h>
using namespace std;

bool isBlocked(int r, int c, int kaiRow, int kaiCol) { // based on kais position, check if he occupies these areas
    return r == kaiRow || c == kaiCol || r - c == kaiRow - kaiCol || r + c == kaiRow + kaiCol;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<bool>> visited(n+1, vector<bool>(n+1, false)); // for one based indexing apparently

    int kai1, kai2, start1, start2, end1, end2;
    cin >> kai1 >> kai2 >> start1 >> start2 >> end1 >> end2;
    visited[start1][start2] = true; // its already visited.
    
    queue<pair<int,int>> q;
    q.push(make_pair(start1, start2));
    
    vector<pair<int,int>> moves = {
		{-1, -1}, {-1, 0}, {-1, 1}, 
		{0, -1},           {0, 1}, 
		{1, -1}, {1, 0}, {1, 1}
	};
	// the ches king moveset, as usual
	// BFS 
    while (!q.empty()) {
		auto [a, b] = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = a + moves[i].first;
			int ny = b + moves[i].second;
			if (!isBlocked(nx, ny, kai1, kai2) && 1 <= nx && nx <= n && 1 <= ny && ny <= n  && !visited[nx][ny]) {
				// if its not blocked or out of bounds, go into that square
				q.push({nx, ny});
				visited[nx][ny] = true;
			}
		}
	}
	if (visited[end1][end2] == true) {
		cout << "YES";
	} else {
		cout << "NO";
	}
    
    
    return 0;
}

// i learnt bfs from this, how to implement for myself 