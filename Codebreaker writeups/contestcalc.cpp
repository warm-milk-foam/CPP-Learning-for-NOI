#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, ll> scores;
    ll N;
    cin >> N;
    for (ll i = 0; i < N; i++) {
		string name;
		ll score;
		cin >> name >> score;
		scores.insert(make_pair(name, score));
    }
    
    ll A;
    cin >> A;
    ll total = 0;
    for (ll i = 0; i < A; i++) {
		string name;
		cin >> name;
		total += scores[name];
	}
	cout << total/A;
	
    
    
    return 0;
}
