#include<iostream>
#include<vector>
using namespace std;

int merge(int arr[], int si, int ei, int mid){

    vector<int>temp;
    int i = si;
    int j = mid+1;
    int inversionCount = 0;

    while(i<=mid && j<=ei){

        if(arr[i] < arr[j]){
            temp.push_back(arr[i++]);
        }

        else if(arr[i] > arr[j]){
            temp.push_back(arr[j++]);
            inversionCount += (mid-i+1);
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
    return inversionCount;
}

int mergesort(int arr[], int si , int ei){

    if(si<ei){
        int mid = si+(ei-si)/2;
        int leftInversion = mergesort(arr,si,mid);
        int rightInversion = mergesort(arr,mid+1,ei);
        int inversionCount = merge(arr,si,ei,mid);
        return leftInversion + rightInversion + inversionCount;
    }
    return 0;
}

void print(int arr[], int n){
    for(int i = 0; i<n ;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

    int n = 6; 
    int arr[] ={6,3,5,2,7};
    
    int inversionCount = mergesort(arr,0,n-1);
    cout << inversionCount << endl;

    return 0;
}