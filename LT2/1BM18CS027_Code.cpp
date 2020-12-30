// top K
#include <bits/stdc++.h> 
using namespace std; 

void kTop(int a[], int n, int k) 
{ 
	vector<int> top(k + 1); // vector of size k+1 to store elements 
	unordered_map<int, int> freq;  // frequency arr
	for (int m = 0; m < n; m++) {  // upto last element
		freq[a[m]]++; // increase freq by 1
		top[k] = a[m]; 
		auto it = find(top.begin(), top.end() - 1, a[m]); // search simiar to top ele
		for (int i = distance(top.begin(), it) - 1; i >= 0; --i) { 
			if (freq[top[i]] < freq[top[i + 1]]) 
				swap(top[i], top[i + 1]); 
			else if ((freq[top[i]] == freq[top[i + 1]]) 
					&& (top[i] > top[i + 1])) 
				swap(top[i], top[i + 1]); 
			else
				break; 
		} 
		// print top k elements 
		for (int i = 0; i < k && top[i] != 0; ++i) 
			cout << top[i] << ' '; 
	} 
	cout << endl; 
} 
int main() 
{ 
	int k; 
    cout << "Enter Value of K: "; cin >> k;
    int n;
    cout<< "Enter Number of elements in array: "; cin >> n;
    cout<< "Enter Numbers in the Array: ";
	int arr[n];
    for (int i = 0; i<n; ++i)
        cin >> arr[i];
    cout << "Output:" << endl;
	kTop(arr, n, k); 
	return 0; 
} 
