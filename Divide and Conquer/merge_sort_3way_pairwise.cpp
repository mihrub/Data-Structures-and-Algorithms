#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[],int si,int mid,int ei){
    vector<int> temp;
    int i = si;
    int j = mid + 1;
    while(i <= mid && j <= ei){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
        }
    }
    while(i <= mid){
        temp.push_back(arr[i++]);
    }
    while(j <= ei){
        temp.push_back(arr[j++]);
    }
    for(int idx = si,x = 0; idx <= ei; idx++){
        arr[idx] = temp[x++];
    }
}

void mergeSort3Pairwise(int arr[],int si,int ei){
    if(si >= ei){
        return;
    }

    int len = ei - si + 1;
    int mid1 = si + len/3 - 1;   
    int mid2 = si + 2*len/3 - 1; 

    mergeSort3Pairwise(arr, si, mid1);
    mergeSort3Pairwise(arr, mid1+1, mid2);
    mergeSort3Pairwise(arr, mid2+1, ei);

    merge(arr, si, mid1, mid2); 
    merge(arr, si, mid2, ei);     
}

int main(){

    int arr[] = {100,20,10,40,20,50,70,30,90,80};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Unsorted Array: ";

    for(int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;    
    mergeSort3Pairwise(arr,0,size-1);

    cout << "Sorted Array: ";
    for(int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
