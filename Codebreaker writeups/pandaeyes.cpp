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
	// this is just a greedy solution in which we just sort for earliest end time and check if a task has a later starting time than a task's end time
	// this is also known as 'Maximum number of non-overlapping intervals'
	// It is optimal because earliest end time means more space to do more stuff
}
