#include<iostream>
using namespace std;

void array_reverse_traversal(int arr[], int n){

    for(int i = n-1; i>=0; i--){
        cout << arr[i] << " ";
    }

}

int main(){

    int n;
    cout << "Enter the size : ";
    cin >> n;

    int arr[n];
    cout << "Taking Input into the array : ";

    for(int i = 0; i<n ; i++){
        cin >> arr[i];
    }

    cout << "Printing the array....\n";

    array_reverse_traversal(arr,n);
      
    return 0;
}

