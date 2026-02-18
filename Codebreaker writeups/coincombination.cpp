// https://codebreaker.xyz/problem/coincombinations
#include <bits/stdc++.h>
using namespace std;

int main () {
	int numCoins, totalValue; // numCoins is the number of coins given to us, and totalValue is the target value we are supposed to make
	cin >> numCoins >> totalValue;
	
	vector<int> dp(totalValue + 1, 0);  // the first value will be the Coin Target Value, and the second how many ways there are to make it
	dp[0] = 1;
	vector<int> coins(numCoins); // the coins and their values
	for (int i = 0; i < numCoins; i++) {
		cin >> coins[i];
	}
    for (int j = 0; j < numCoins; j++) {      // loop over coins
        int c = coins[j];
        for (int i = c; i <= totalValue; i++) {   // loop over sums
            dp[i] += dp[i - c];                 // add ways using this coin
            dp[i] %= 13371337;                  // modulo as required
        }
    }

    cout << dp[totalValue] << "\n";
    return 0;
	
	return 0;
}
