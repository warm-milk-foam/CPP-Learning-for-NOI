#include <bits/stdc++.h>
using namespace std;

int main() {
	long long x;
	cin >> x;
	
	if (x <= 1) {
		cout << "Not Prime";
		return 0;
	} else if (x <= 3) {
		cout << "Prime";
		return 0;
	} else if (x % 2 == 0 || x % 3 == 0) {
		cout << "Not Prime";
		return 0;
	} else {
		for (int i = 2; i <= sqrt(x); i++) {
			if (x % i == 0) {
				cout << "Not Prime";
				return 0;
			}
		}
		cout << "Prime";
		return 0;
	}

}

/* i had to chatgpt what makes a number prime, soo
1) Not 1
2) Not divisible by every number until sqrt(x)



*/