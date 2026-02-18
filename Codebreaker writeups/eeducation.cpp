#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	ll N, M;
	cin >> N >> M;
	vector<ll> original(N);
	unordered_set<ll> key(N);
	
	for (ll i = 0; i < N; i++) cin >> original[i];
	for (ll i = 0; i < M; i++) {
		ll x;
		cin >> x;
		key.insert(x);
	}
	reverse(original.begin(), original.end());
	// to check quickly, use an unordered set
	
	for (int i = 0; i < N; i++) {
		auto it = key.find(original[i]);
		if (it != key.end()) { // that means, that element is found
			cout << *it << " ";
		}
	}
	

}
// this is just a challenge on checking using an unordered set without hitting TLE due to slow ass vectors