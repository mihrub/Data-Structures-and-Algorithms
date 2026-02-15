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

    int key;
    cout << "Key : ";
    cin >> key;
    int flag = 0;

    for(int i = 0; i<n; i++){
        if(arr[i] == key){
            flag = 1;
        }
    }

    if(flag == 1){
        cout << "Found" << endl;
    }
    else{
        cout << "Not Found" << endl;
    }   

    return 0;
}

