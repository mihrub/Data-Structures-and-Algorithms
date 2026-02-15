#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int si, int ei, int mid){

    vector<int>temp;
    int i = si;
    int j = mid+1;

    while(i<=mid && j<=ei){

        if(arr[i] < arr[j]){
            temp.push_back(arr[i++]);
        }

        else if(arr[i] > arr[j]){
            temp.push_back(arr[j++]);
        }
    }

    while(i<=mid){
        temp.push_back(arr[i++]);
    }

    while(j<=ei){
        temp.push_back(arr[j++]);
    }

    for(int k = si, x = 0; k<=ei; k++){
        arr[k] = temp[x++];
    }
}

void mergesort(int arr[], int si , int ei){

    if(si>=ei){
        return;
    }

    int mid = si+(ei-si)/2;

    mergesort(arr,si,mid);
    mergesort(arr,mid+1,ei);
    merge(arr,si,ei,mid);

}

void print(int arr[], int n){
    for(int i = 0; i<n ;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

    int n = 6; 
    int arr[] ={6,3,7,5,2,4};
    
    mergesort(arr,0,n-1);
    print(arr,n);

    return 0;
}