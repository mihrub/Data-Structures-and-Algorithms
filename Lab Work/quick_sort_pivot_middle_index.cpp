#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int partition(int arr[], int si, int ei){
    int mid = si + (ei - si) / 2;
    swap(arr[mid], arr[ei]);
    
    int i = si - 1;
    int pivot = arr[ei];
    
    for(int j = si; j < ei; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    i++;
    swap(arr[i], arr[ei]);
    
    return i;
}

void quickSort(int arr[], int si, int ei){
    if(si >= ei){
        return;
    }
    int pivot_index = partition(arr, si, ei);
    quickSort(arr, si, pivot_index - 1);
    quickSort(arr, pivot_index + 1, ei);
}

int main(){
    
    int arr[] = {100, 20, 10, 40, 20, 50, 70, 30, 90, 80};
    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, size - 1);

    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";        
    
    return 0;
}