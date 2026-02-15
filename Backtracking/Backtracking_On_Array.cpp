#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

void print(int arr[],int n){
    for(int i = 0; i<n; i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
}

void assign(int arr[], int n, int i){
    if(i == n){
        print(arr,n);
        return;
    }
    arr[i] = i+1;
    assign(arr,n,i+1);
    arr[i]-=2;
}

int main(){
      
    int n;
    cin >> n;
    
    int arr[n];

    assign(arr,n,0);
    print(arr,n);

    return 0;
}