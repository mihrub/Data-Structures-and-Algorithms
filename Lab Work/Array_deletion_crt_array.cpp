#include<iostream>
using namespace std;
int main(){

    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i<n ; i++){
        cin >> arr[i];
    }

    int pos;
    cin >> pos ;

    int crr[n-1];

    for(int i = 0,j = 0; i<n ;i++){
        if(pos == i){
            continue;
        }
        crr[j++] = arr[i];
    }

    for(int i = 0 ; i<n-1; i++){
        cout << crr[i] << " ";
    }
 
    return 0;
}