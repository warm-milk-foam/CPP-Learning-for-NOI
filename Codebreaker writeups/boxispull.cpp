#include <bits/stdc++.h>
using namespace std;

int main() {
    long long cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        pair<long long, long long> start;
        pair<long long, long long> end;
        cin >> start.first >> start.second >> end.first >> end.second;

        long long x_difference = abs(end.first - start.first);
        long long y_difference = abs(end.second - start.second);

        long long minimumTime = x_difference + y_difference;

        // Add 2 seconds for each 90-degree turn
        if (x_difference > 0 && y_difference > 0) {
            minimumTime += 2;
        }

        cout << minimumTime << endl;
    }
    return 0;
}
