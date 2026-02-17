#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<string> numbers(N);
    for (int i = 0; i < N; i++) cin >> numbers[i];

    sort(numbers.begin(), numbers.end(), [](const string &a, const string &b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
    });

    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << numbers[i];
    }
    cout << '\n';
}
// chatgpt solution, full solves...

#include <bits/stdc++.h>
using namespace std;

int alt() {
	long long N;
	cin >> N;
	vector<long long> numbers(N);
	for (long long i = 0; i < N; i++) cin >> numbers[i];
	
	sort(numbers.begin(), numbers.end());
	for (long long i = 0; i < N; i++) cout << numbers[i] << " ";
	cout << '\n';
}	
// original solution... almost full solves but task 4 

// this challenge is trickery because they want you to know that long long isnt enough. instead, you're meant to use string and compare length/lex order