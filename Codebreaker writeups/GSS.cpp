#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.rbegin(), v.rend());  // sort descending

    long long total_cost = 0;
    for (int i = 0; i < n; i++) {
        // every 4th item (i % 4 == 3) is free
        if ((i + 1) % 4 != 0)
            total_cost += v[i];
    }

    cout << total_cost << "\n";
    return 0;
}
