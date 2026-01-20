#include <bits/stdc++.h>
using namespace std;

int main() {
	int numTasks;
	cin >> numTasks;
	
	vector<pair<int, int>> tasks(numTasks); // first value will be end time, second will be start time btw
	
	for (int i = 0; i < numTasks; i++) {
		int x, y;
		cin >> x >> y;
		tasks[i].first = y;
		tasks[i].second = x;
		
	} 
	sort(tasks.begin(), tasks.end());
	long long completed = 0;
	long long end_time = 0;
	for (auto &t : tasks) {
    if (t.second >= end_time) {   // start >= last end
			completed++;
			end_time = t.first;  // update end time
		}
	}

	cout << completed;

	
	
}
