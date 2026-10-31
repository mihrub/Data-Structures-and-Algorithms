#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
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

void mergeSort(int arr[],int si,int ei){
    if(si >= ei){
        return;
    }
    int mid = si + (ei-si) / 2;
    mergeSort(arr,si,mid);
    mergeSort(arr,mid+1,ei);
    merge(arr,si,mid,ei);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[] = {100,20,10,40,20,50,70,30,90,80};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr,0,size-1);

    for(int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;    
    
    return 0;
}