#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<long long> Q;
    for (int i = 0; i < N; i++) {
        long long banana;
        cin >> banana;
        if (banana > 0) Q.push_back(banana);  // remove negatives and zero
    }

    sort(Q.begin(), Q.end(), greater<long long>());

    long long ans = 0;
    int size = Q.size();

    // Sum every K-th element to get minimum of each smoothie
    for (int i = K - 1; i < size; i += K) {
        ans += Q[i];
    }

    cout << ans;
}
