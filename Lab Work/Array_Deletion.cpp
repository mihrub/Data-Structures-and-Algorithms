#include<iostream>
using namespace std;
int main(){
      
    int n;
    cout << "Enter the size : ";
    cin >> n;

    int arr[n];
    cout << "Taking Input into the array : ";

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    int pos;
    cout << "Position : ";
    cin >> pos;

    for(int i = pos-1; i<n-1; i++){
        arr[i] = arr[i+1];
    }

    cout << "Printing the array after deleting..." << endl;

    for(int i = 0; i<n-1; i++){
        cout << arr[i] << " ";
    }

    return 0;
}

