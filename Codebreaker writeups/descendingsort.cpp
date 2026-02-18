#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
	ll N;
	cin >> N;
	
	vector<ll> numbers(N);
	for (ll i = 0; i < N; i++) cin >> numbers[i];
	sort(numbers.rbegin(), numbers.rend());

	for (ll i = 0; i < N; i++) cout << numbers[i] << " ";
}
