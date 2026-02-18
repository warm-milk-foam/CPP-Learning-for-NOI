// https://codebreaker.xyz/problem/management

#include <bits/stdc++.h>
using namespace std;

int main () {
	int N;
	cin >> N;
	vector<int> people(N, 0);
	
	for (int i = 0; i < N-1; i++) {
		int x;
		cin >> x;
		people[x-1]++;
	}
	for (int i = 0; i < N; i++) {
		cout << people[i] << "\n";
	}
}
