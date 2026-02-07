#include <bits/stdc++.h>
using namespace std;

int main() {
    // https://codebreaker.xyz/problem/frogs
    long long hills, frogs, mosquitoes;
    cin >> hills >> frogs >> mosquitoes; // no. of which respectively

    vector<long long> jump_power(frogs);
    vector<long long> mosquito_islands(mosquitoes);

    for (int i = 0; i < frogs; i++) cin >> jump_power[i];
    for (int i = 0; i < mosquitoes; i++) cin >> mosquito_islands[i];

    vector<long long> killed(frogs, 0);

    for (int i = 0; i < frogs; i++) {
        for (int j = 0; j < mosquitoes; j++) {
            if (mosquito_islands[j] % jump_power[i] == 0) {
                killed[i]++;
            }
        }
    }

    long long min_killed = *min_element(killed.begin(), killed.end());

    vector<int> best_frogs;
    for (int i = 0; i < frogs; i++) {
        if (killed[i] == min_killed) {
            best_frogs.push_back(i + 1); // 1-based indexing fix ughghhg
        }
    }

    cout << best_frogs.size() << "\n";
    for (int i = 0; i < best_frogs.size(); i++) {
        cout << best_frogs[i];
        if (i + 1 < best_frogs.size()) cout << " ";
    }
    cout << "\n";

    return 0;
}
