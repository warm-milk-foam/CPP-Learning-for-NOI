#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, R; // number of cats, number of relationships
    
    cin >> N >> R;
    vector<int> cats(N, 0); // at first, i used a vector of pairs, but MLE so i cut it down to just the number
    
    // For N number of cats, the list is from 0 to N-1
    
    for (int i = 0; i < R; i++) {
		int x, y;
		cin >> x >> y;
		if (x != y) { // if said cat is not friends with himself
			cats[x-1] = 1;
			cats[y-1] = 1;
		}	
	}
	int alone = 0; // number of cats with friends
	for (int j = 0; j < N; j++) {
		if (cats[j] == 0) {
			alone++;
		}
	}
	cout << alone;
}
// this is an almost full solve of the challenge, but it hits RTE(6) for some reason, so the score is 89/100