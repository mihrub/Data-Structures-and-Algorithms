#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        int min_index = i;
        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        swap(arr[i],arr[min_index]);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[] = {100,20,10,40,20,50,70,30,90,80};
    int size = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr,size);

    for(int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}