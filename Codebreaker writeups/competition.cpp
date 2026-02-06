#include <bits/stdc++.h>
using namespace std;
// https://codebreaker.xyz/problem/competition
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    long long total = 0;
    vector<int> A(n), B(n); // A is physics, B is bio

    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];
    vector<pair<int,int>> diff(n);
    for (int i = 0; i < n; i++) {
        diff[i] = {A[i] - B[i], i};
    }
	
    sort(diff.rbegin(), diff.rend()); // today i learnt rbegin() and rend() make for descending

    // pick top diff students for physics
    vector<bool> isPhysics(n, false);
    for (int i = 0; i < a; i++) {
        int idx = diff[i].second;
        total += A[idx];
        isPhysics[idx] = true; // mark that this student is in physics
    }

    for (int i = 0; i < n; i++) {
        if (!isPhysics[i]) {
            total += B[i];
        }
    }

    cout << total << "\n";
    return 0;
}
