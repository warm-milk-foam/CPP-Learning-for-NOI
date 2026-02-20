#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<long long> weight;
	vector<long long> profit;
	long long n, W;
	cin >> n >> W;
	
	for (long long i = 0; i < n; i++) {
		long long x, y;
		cin >> x >> y;
		weight.push_back(x);
		profit.push_back(y);
	}
	

    // DP table with dimensions (n+1) x (W+1)
    vector<vector<long long>> dp(n + 1, vector<long long>(W + 1, 0));

    // Build the DP table
    for (int i = 1; i <= n; i++) {
        for (long long w = 0; w <= W; w++) {
            if (weight[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight[i - 1]] + profit[i - 1]);
            else
                dp[i][w] = dp[i - 1][w];  // Skip the item if it doesn't fit
        }
    }

    cout << dp[n][W] << endl;
    return 0;
}
