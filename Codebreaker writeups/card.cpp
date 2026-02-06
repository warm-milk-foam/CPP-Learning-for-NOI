#include <bits/stdc++.h>
using namespace std;
// https://codebreaker.xyz/problem/card
//ai generated solution, but welp.. i suck.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, k;
    string moves;
    cin >> m >> k >> moves;

    moves.pop_back(); // remove '.'

    auto get_label = [&](int p) {
        for (int i = (int)moves.size() - 1; i >= 0; i--) {
            if (moves[i] == 'A') {
                if (p == m - 1) p = 0;
                else p++;
            } else { // 'B'
                if (p == m - 1) p = 1;
                else if (p != 0) p++;
            }
        }
        return p;
    };

    cout << get_label(k - 1) << " "
         << get_label(k) << " "
         << get_label(k + 1) << "\n";
}
