#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int N;
	cin >> N;
	vector<int> numbers(N);
	int median = N/2;
	for (int i = 0; i < N; i++) cin >> numbers[i];
	cout << numbers[median];
	
}