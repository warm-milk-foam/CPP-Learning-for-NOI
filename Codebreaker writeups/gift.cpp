#include <bits/stdc++.h>
using namespace std;

int main() {
    long long num, change;
    cin >> num >> change;

    long long to_beat;
    cin >> to_beat;  // first value

    long long gifts = 0;
    for (int i = 1; i < num; i++) {
        long long x;
        cin >> x;

        if (to_beat - x >= change) {
            gifts++;
        }
        to_beat = x;
    }

    cout << gifts;
}
