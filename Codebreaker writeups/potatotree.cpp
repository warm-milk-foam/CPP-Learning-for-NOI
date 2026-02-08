#include <bits/stdc++.h>
using namespace std;

int main() {
  // https://codebreaker.xyz/problem/potatotree
  // prefix list challenge regarding unique items
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);
    
    int trees, queries;
    cin >> trees >> queries;

    vector<int> tree_list(trees);
    vector<int> query_list(queries);
    vector<int> unique_fruits(trees);
    unordered_set<int> seen;

    for (int i = 0; i < trees; i++) cin >> tree_list[i];

    for (int i = 0; i < queries; i++) cin >> query_list[i];

    int count = 0;

    for (int i = 0; i < trees; i++) {
        if (seen.find(tree_list[i]) == seen.end()) {
            seen.insert(tree_list[i]);
            count++;
        }
        unique_fruits[i] = count;
    }

    // Answer queries
    for (int i = 0; i < queries; i++) {
        int L = query_list[i];
        cout << unique_fruits[L - 1] << " ";
    }

    return 0;
}
