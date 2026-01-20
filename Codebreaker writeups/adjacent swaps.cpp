# C++ Challenge: Adjacent Swaps  
Description:  
```
Physicist S has an array. He wants to sort the array in increasing order. However, as he is very lazy, he will only swap two adjacent elements in the array, and he wishes to have the array sorted in the minimum number of steps.

Help Physicist S by writing a program that tells him how to sort his array.
Input

The first line of input contains a single integer, N, the size of Physicist S's array.

The second line of input contains N integers, representing Physicist S's array.
Output

The first line of output should contain a single integer, ans, the minimum number of swaps required to sort the array.

The next ans lines of input should contain one integer each, i, denoting a swap between the ith and (i + 1)th element. If 1 ≤ i < N is not satisfied, you will receive a wrong answer verdict.
```
Basically, all we have to do is:  
1) Run a while loop on the array, to keep swapping adjacent swaps, until we reach an iteration in which the loop is finally sorted,  
2) Keep track of the first number we need to swap with the second,  
3) Count how many swaps we make.

We will use a vector `numbers` to keep track of the numbers list, a vector `swap_sequence` to collate all the swaps, an int `numMoves` to count, and a bool `is_correct` to tell us when the while loop should finally stop.  

Solution:

// https://codebreaker.xyz/problem/adjacentswaps
#include <bits/stdc++.h>
using namespace std;

int main () {
	vector<int> numbers; // the unsorted ones we get
	vector<int> swap_sequence; // the list of swaps to output later
	int num; // number of numbers in vector
	cin >> num;
	int numMoves = 0; // minimum number of moves to make
	
	for (int i = 0; i < num; i++) {
		int x;
		cin >> x;
		numbers.push_back(x);
	}
	bool is_correct = false; // change this condition to true when we figured out that the sequence is sorted
	while (!is_correct) {
		is_correct = true;
		for (int i = 0; i < num-1; i++) {
			if (numbers[i] > numbers[i+1]) {
				swap(numbers[i], numbers[i+1]);
				numMoves++;
				is_correct = false;
				swap_sequence.push_back(i+1);
			}
		}
	} 
	cout << numMoves << endl;
	for (int j = 0; j < numMoves; j++) {
		cout << swap_sequence[j] << endl;
	}
}
