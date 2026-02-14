#include <bits/stdc++.h>
using namespace std;
// https://codebreaker.xyz/problem/lengthsort

int main() {
	int n;
	cin >> n;
	
	vector<tuple<int, int, string>> strings; 
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		strings.push_back(make_tuple(-(int)x.length(), i, x)); // first is string, second is length, third is their index
	}
	sort(strings.begin(), strings.end());
	// as a workaround, i decided to make the length negative so the default sort would work, hehe
	for (auto &t : strings)
        cout << get<2>(t) << "\n";
	
}
