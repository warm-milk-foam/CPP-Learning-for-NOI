// https://codebreaker.xyz/problem/ccs

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, Q;
    cin >> N >> Q;

    set<long long> asleep;

    while (Q--) {
        string input;
        cin >> input;

        if (input == "WAKE") {
            long long x;
            cin >> x;
            asleep.erase(x);
        }
        else if (input == "SLEEP") {
            long long x;
            cin >> x;
            asleep.insert(x);
        }
        else if (input == "TRANSMIT") {
            long long x, y;
            cin >> x >> y;

            auto it = asleep.lower_bound(x);

            if (it != asleep.end() && *it <= y)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }
}


// btw, here was my original solution, but it was too slow and it didnt work correctly...
