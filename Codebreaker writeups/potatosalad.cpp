#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    int a, b;
    int maximum =   0;
    int hi;
    cin >> a >> b; // Read a and b
    int arr[a]; // Define the array with size a
    for (int i =   0; i < a; i++) {
      cin >> arr[i]; // Read a numbers into arr
    }
    sort(arr, arr + a, greater<int>()); // Sort the array in descending order
    for (int x =   0; x < b; x++) { // Sum the first b largest numbers
        maximum += arr[x];
    }
    cout << maximum; // Output the sum
}
