#include <bits/stdc++.h>
using namespace std;
int main() {
    int cats, power;
    cin >> cats >> power;

    vector<int> cat_arr(cats);
    for (int i = 0; i < cats; i++) {
        cin >> cat_arr[i];
    }

    int max_cats_defeated = 0;
    int start = 0;
    int current_power = power;

    for (int end = 0; end < cats; end++) {
        current_power -= cat_arr[end];

        while (current_power < 0 && start <= end) {
            current_power += cat_arr[start];
            start++;
        }

        max_cats_defeated = max(max_cats_defeated, end - start + 1);
    }

    cout << max_cats_defeated;
    return 0;
}
