#include<iostream>
#include<algorithm>
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

void binary_search(int arr[],int si,int ei,int key){

    if(si > ei){
        cout << "Not Found" << endl;
        return;
    }

    int mid = (si+ei)/2;

    if(arr[mid] == key){
        cout << "Found" << endl;
        return;
    }

    else if(arr[mid] > key){
        binary_search(arr,si,mid-1,key);
    }
    else if(arr[mid] < key){
        binary_search(arr,mid+1,ei,key);
    }

}

int main(){

    int n;
    cout << "Enter the size : ";
    cin >> n;
    int arr[n];
    cout << "Taking input into the array : ";

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    bubble_sort(arr,n);
    cout << "Printing the array after sorting..." << endl;

    for(int i = 0; i<n; i++){
        cout << arr[i] <<  " ";
    }

    cout << endl;
    int key;
    cout << "Key : ";
    cin >> key;

    binary_search(arr,0,n-1,key);

    return 0;
}

