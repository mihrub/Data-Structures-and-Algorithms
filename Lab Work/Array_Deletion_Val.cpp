#include<iostream>
using namespace std;
int main(){

    int n;
    cout << "Enter the size : ";
    cin >> n;

    int arr[n];
    cout << "Taking Input into the array : ";

    for(int i = 0; i<n ; i++){
        cin >> arr[i];
    }

    int val;
    cout << "Value : ";
    cin >> val;
    
    int delete_idx;

    for(int i = 0; i<n; i++){
        if(val == arr[i])
            delete_idx =  i;
    }    

    for(int i = delete_idx; i<n-1; i++){
        arr[i] = arr[i+1];
    }

    cout << "Printing the array after deleting..." << endl;

    for(int i = 0; i<n-1; i++){
        cout << arr[i] << " ";
    }
    return 0;
}

