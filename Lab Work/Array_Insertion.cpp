#include<iostream>
using namespace std;
int main(){

    int n;
    cout << "Enter the size : ";
    cin >> n; 

    int arr[n+1];
    cout << "Taking input into the array : ";

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    int pos,val;
    cout << "Position : ";
    cin >> pos;
    cout << "Value : ";
    cin >> val;
    

    for(int i = n ; i>=pos ; i--){
        arr[i] = arr[i-1];
    }

    arr[pos-1] = val;
    cout << "Printing the Array : ";

    for(int i = 0; i<n+1; i++){
        cout << arr[i] << " ";
    }

    return 0;
}

