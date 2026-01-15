# C++ Challenge: Flybot
Description:  
```
Ranald the cat is coding a flybot today! The main objective of this flybot is to get from the top left hand corner of the wall to the bottom right hand corner. The flybot will be at the top left hand corner initially.

Walls are described using a grid system where each cell represents a centimetre square, where by '.' denotes a empty section of a wall and 'X' denotes an object (such as posters or pictures pinned to the wall). The flybot cannot pass through such objects.

The flybot can only move right since it is poorly coded, it also can only move downwards as it does not have enough power to overcome gravity.

Ranald the cat wonders how many different routes are there for his flybot to complete its objective. As this number can be very huge, he just needs to know the remainder of that number when divided by 1000000007.

It should be also noted that the top left hand corner and the bottom right hand corner of the wall will only be '.' and not 'X'.
```
The keywords 'how many different routes' suggest that this is a dynamic programming problem, as since there are multiple possible paths that can be taken.  
Seeing that you cannot calculate a whole board at once, we have to craft the approach to slowly expand to the board

We will make a 2D vector table so that each number corresponds to each tile, and every number will be the number of ways to get to that tile.  
Then, tiles will be the sum of the left and top ones, and 'X' become 0 (because you cannot move through it)  
So, when we finish the board, the rightmost-bottom corner tile is our sum.  

```
// https://codebreaker.xyz/problem/flybot
#include <bits/stdc++.h>
using namespace std;


int main () {
	long long height, width;
	cin >> height >> width;
	vector<vector<int>> dp(height, vector<int>(width, 0));
	vector<string> grid(height);
	for (int i = 0; i < height; i++) {
		cin >> grid[i];
	}
	dp[0][0] = 1;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (i == 0 && j == 0) continue;
			if (grid[i][j] == 'X') {
				dp[i][j] = 0;
				continue;
			}
			long long ways = 0;
			if (i > 0) ways += dp[i - 1][j];
			if (j > 0) ways += dp[i][j - 1];
				
			dp[i][j] = ways % 1000000007;
		}
	}

	cout << dp[height - 1][width - 1] << "\n";
	return 0;
}

```