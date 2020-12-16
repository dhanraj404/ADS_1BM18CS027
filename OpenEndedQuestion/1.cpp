/*
Given an array of N distinct elements, the task is to find all elements in array except two greatest elements.
*/
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int test; cin>>test;
    while (test--)
    {
        int n; cin >> n ;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        for(int j=0; j<n-2;j++)
            cout<< arr[j] << " ";
        cout<<endl;
    }   
}