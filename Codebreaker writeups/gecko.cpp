#include <bits/stdc++.h>
using namespace std;

int main() {
	int height, width;
	cin >> height >> width;
	
	vector<vector<int>> grid(height, vector<int>(width));		
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> grid[i][j];
		}
	}
	for (int i = 1; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0) { // check if it is the first
				grid[i][j] += max(grid[i-1][j], grid[i-1][j+1]);
			} else if (j == width-1) { // check if it is the last
				grid[i][j] += max(grid[i-1][j-1], grid[i-1][j]);
			} else { // else it must be a tile reachable by the top 3 above it
				grid[i][j] += max({
					grid[i-1][j-1],
					grid[i-1][j],
					grid[i-1][j+1]
				});
			}
		}
	}
	cout << *max_element(grid[height-1].begin(), grid[height-1].end());
	return 0;
}
