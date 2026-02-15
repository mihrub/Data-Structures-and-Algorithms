#include<iostream>
using namespace std;
int main(){

    int n;
    cout << "Enter the Size : ";
    cin >> n; 

    int arr[n];
    cout << "Taking input into the array : ";
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    int key,val;
    cout << "Key : ";
    cin >> key;
    cout << "Value : ";
    cin >> val;

    int count = 0 , flag = 0;

    for(int i = 0; i<n; i++){
        if(arr[i] == key){

        if(count == 0){
            cout << "Index : ";
        }
            cout << i << " ";
            arr[i] = val;
            flag = 1;
        }
    }

    cout << endl;
    
    if(flag == 1){
    cout << "Printing the array after changing the element..." << endl;
    for(int i = 0; i<n ; i++){
        cout << arr[i] << " ";
    }
    }
    else{
        cout << endl;
        cout << "Key Not Found" << endl;
    } 
    return 0;
}


