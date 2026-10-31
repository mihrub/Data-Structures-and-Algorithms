#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

int binarySearch(int arr[], int n, int key){
    int start = 0;
    int end = n;

    while (start <= end){
        int mid = (start + end) / 2;

        if (arr[mid] == key){
            return mid;
        }

        else if (arr[mid] < key){
            start = mid + 1;
        }

        else if (arr[mid] > key){
            end = mid - 1;
        }
    }
    return -1;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[] = {1,2,5,14,20,70};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 30;
    cout << binarySearch(arr,size,key) << endl;

    return 0;
}