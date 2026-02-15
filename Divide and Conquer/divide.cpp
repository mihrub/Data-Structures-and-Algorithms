#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

void divide(int arr[],int left,int right){  // Time Complexity - O(log(N))

    for(int i = left; i<=right;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    if(left>=right){
        return;
    }

    int mid = (left+right)/2;
    divide(arr,left,mid);
    divide(arr,mid+1,right);
}


int main(){
      
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    divide(arr,0,n-1);

    return 0;
}