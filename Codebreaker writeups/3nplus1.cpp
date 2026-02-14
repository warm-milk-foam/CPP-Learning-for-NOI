#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int start, time_end;
    cin >> start >> time_end;

    if (start == 1) { // Already gone at time >= 1
        cout << -1;
        return 0;
    }

    for (int i = 1; i < time_end; i++) {
        if (start % 2 == 0) {
            start /= 2;
        } else {
            start = start * 3 + 1;
        }

        if (start == 1) {
            cout << -1;
            return 0;
        }
    }

    cout << start;
    return 0;
}
// this solution was helped by AI, the original solution (which almost passed all test case) is here.
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int start, time_end;
    cin >> start >> time_end;

    if (start == 1) { // Already gone at time >= 1
        cout << -1;
        return 0;
    }

    for (int i = 1; i < time_end; i++) {
        if (start % 2 == 0) {
            start /= 2;
        } else {
            start = start * 3 + 1;
        }

        if (start == 1) {
            cout << -1;
            return 0;
        }
    }

    cout << start;
    return 0;
}
