// https://codebreaker.xyz/problem/monsters2
/*
Strategy: 
1) Find if its optimal to kill monsters at mines or by decreasing their health
2) Find which monsters to put at which mines

Find the cost of:
1) Blowing monster on mines on their left
2) Blowing monster on mines on their right
3) Decreasing their health manually

You could reuse the mines again, but don't. You are gonna bring the monsters there first and explode it, which saves you the +1 dollar cost penalty

Costs 1 and 2 differ on whether 1 mine is activated or 2 mines activated (where 1 mine is closer)
by price of 1 dollars

I won't submit this solution because its entirely AI generated, I would like to solve this properly

*/
// https://codebreaker.xyz/problem/monsters2
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<pair<ll,ll>> monsters(N);
    vector<ll> mines(K);

    for (int i = 0; i < N; i++) {
        cin >> monsters[i].first >> monsters[i].second; // position, health
    }

    for (int i = 0; i < K; i++) {
        cin >> mines[i];
    }

    sort(monsters.begin(), monsters.end());
    sort(mines.begin(), mines.end());

    // ⭐ Step 1: Assume we kill ALL monsters manually
    ll baseCost = 0;
    for (auto [pos, health] : monsters) {
        baseCost += health;
    }

    // ⭐ Step 2: Track total savings per mine
    vector<ll> mineSaving(K, 0);

    for (auto [pos, health] : monsters) {

        // find nearest mine using binary search
        auto it = lower_bound(mines.begin(), mines.end(), pos);

        ll bestDist = LLONG_MAX;
        int bestMine = -1;

        // right mine
        if (it != mines.end()) {
            ll dist = *it - pos;
            if (dist < bestDist) {
                bestDist = dist;
                bestMine = it - mines.begin();
            }
        }

        // left mine
        if (it != mines.begin()) {
            ll dist = pos - *prev(it);
            if (dist < bestDist) {
                bestDist = dist;
                bestMine = prev(it) - mines.begin();
            }
        }

        // ⭐ Saving if we use the mine instead of killing manually
        ll saving = health - bestDist;

        if (saving > 0) {
            mineSaving[bestMine] += saving;
        }
    }

    // ⭐ Step 3: Apply mines that are worth activating
    ll answer = baseCost;

    for (int j = 0; j < K; j++) {
        if (mineSaving[j] > 1) {
            // activating mine costs 1, so net saving is (saving - 1)
            answer -= (mineSaving[j] - 1);
        }
    }

    cout << answer << "\n";
}

