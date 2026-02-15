#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
int main(){
      
    int n;
    int arr[n];

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    int val;
    cin >> val;

    for(int i = 0; i<n; i++){
        if(arr[i] == val){
            cout << "Found" << endl;
            return 0;
        }
    }
    cout << "Not Found" << endl;

    return 0;
}