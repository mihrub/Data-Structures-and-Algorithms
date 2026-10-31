#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

int linearSearch(int arr[], int n, int key){
    for (int i = 0; i < n; i++){
        if (arr[i] == key){
            return i;
        }
    }
    return -1;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[] = {10,20,30,40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 20;
    cout << linearSearch(arr,size,key) << endl;

    return 0;
}