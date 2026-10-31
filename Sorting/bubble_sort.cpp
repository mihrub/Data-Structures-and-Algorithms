#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

void bubbleSort(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[] = {33,10,4,1,44,5,2,9,2,5,22,11};
    int size = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr,size);

    for(int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}