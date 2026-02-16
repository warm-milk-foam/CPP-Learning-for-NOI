#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, T;
    cin >> N >> T;

    long long total = 0;
    for (long long i = 1; i <= N; i++) {
        total += T / i;
    }

    cout << total << '\n';
}
