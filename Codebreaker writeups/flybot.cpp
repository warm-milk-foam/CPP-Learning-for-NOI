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
			if (i > 0) ways += dp[i - 1][j]; // check row
			if (j > 0) ways += dp[i][j - 1]; // check column
				
			dp[i][j] = ways % 1000000007;
		}
	}

	cout << dp[height - 1][width - 1] << "\n";
	return 0;
}

