#include <bits/stdc++.h>
using namespace std;

unsigned long long combination(int n, int k) {
  // taken online lol
    unsigned long long result = 1;

    // Use symmetry to reduce work
    if (k > n - k)
        k = n - k;

    for (int i = 1; i <= k; i++) {
        result = result * (n - i + 1) / i;
    }

    return result;
}

int main() {
  // its just a binomial theorem problem
  // https://codebreaker.xyz/problem/pascal
    int r, c;
    cin >> r >> c;

    cout << combination(r - 1, c - 1) << endl;

    return 0;
}
