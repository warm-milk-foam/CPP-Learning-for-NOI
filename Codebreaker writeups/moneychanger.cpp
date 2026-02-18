#include <bits/stdc++.h>
using namespace std;


// Function to calculate the minimum number of coins needed
int minCoins(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1); // Initialize dp array with a large value
    dp[0] = 0; // Base case

    for (int i = 1; i <= amount; ++i) {
        for (const int& coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    vector<int> coins; // Example coin denominations
    int amount;
	int num_coins;
	cin >> num_coins >> amount;
	for (int i = 0; i < num_coins; i++) {
		int x;
		cin >> x;
		coins.push_back(x);
	} 
	

    int result = minCoins(coins, amount);

    if (result != -1) {
        cout << result << std::endl;
    } else {
        cout << "-1";
	}
}
