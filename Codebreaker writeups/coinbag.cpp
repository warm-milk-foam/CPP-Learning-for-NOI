// https://codebreaker.xyz/problem/coinbag
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numCoins, size;
    cin >> numCoins >> size;

    vector<pair<int,int>> coins(numCoins);
    for (int i = 0; i < numCoins; i++) {
        cin >> coins[i].first >> coins[i].second;
    }

    vector<int> dp(size + 1, 0);

    for (auto &c : coins) {
        int w = c.first, v = c.second;
        for (int cap = size; cap >= w; cap--) {
            dp[cap] = max(dp[cap], dp[cap - w] + v);
        }
    }

    cout << dp[size] << "\n";
    return 0;
}
