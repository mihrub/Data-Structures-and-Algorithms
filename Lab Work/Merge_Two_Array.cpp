#include<iostream>
using namespace std;

void bubble_sort(int arr[], int n){

    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){

    int n;
    cout << "Enter the size for Array 1: ";
    cin >> n; 

    int arr[n];
    cout << "Taking input into the array 1 : ";
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    int m;
    cout << "Enter the size for Array 2: ";
    cin >> m;

    int crr[m];
    cout << "Taking input into the array 2 : ";

    for(int j = 0; j<m; j++){
        cin >> crr[j];
    }

    bubble_sort(arr,n);
    bubble_sort(crr,m);

    int trr[m+n];
    int k = 0,i = 0,j = 0;

    while(i<n && j<m){
        
        if(arr[i] >= crr[j]){
            trr[k++] = crr[j++];
        }
        else if(arr[i] <= crr[j]){
            trr[k++] = arr[i++];
        }
    }

    while(i < n){
        trr[k++] = arr[i++];
    }

    while(j < m){
        trr[k++] = crr[j++];
    }

    cout << "Printing the Merged Sorted Array : ";

    for(int l = 0; l<(m+n); l++){
        cout << trr[l] << " ";
    }
    
    return 0;
}