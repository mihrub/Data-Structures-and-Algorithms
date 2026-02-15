#include<iostream>
using namespace std;
int main(){

    int n;
    cout << "Enter the size : ";
    cin >> n; 

    int arr[n];
    cout << "Taking input into the array : ";
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    int key;
    cout << "Key : ";
    cin >> key;

    int flag = 0 , count = 0;

    for(int i = 0; i<n; i++){
        if(arr[i] == key){
            if(count == 0){
                cout << "Index : ";
            }
            flag = 1;
            cout << i << " ";
            count++;
        }
    }
    
    if(flag == 1){
    cout << endl;
    cout << "Frequency of the key : ";
    cout << count << endl;
    }

    else{
        cout << endl;
        cout << "Key Not Found" << endl;
    }

    return 0;
}

