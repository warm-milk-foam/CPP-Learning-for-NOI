#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    // Input the number of integers
    int n;
    cin >> n;

    vector<int> board(n);
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }

    // Initialize variables for Kadane's algorithm
    int currentMin = 0;
    int globalMin = INT_MAX;

    for (int i = 0; i < n; ++i) {
        // Update the current minimum subarray sum
        currentMin = min(board[i], currentMin + board[i]);

        // Update the global minimum
        globalMin = min(globalMin, currentMin);
    }

    // Output the result
    cout << globalMin << endl;

    return 0;
}