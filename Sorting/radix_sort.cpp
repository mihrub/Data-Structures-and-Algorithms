#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

void countSort(int arr[],int n, int exp){

    int result[n];
    int count[10] = {0};

    for(int i = 0; i<n; i++){
        count[(arr[i] / exp) % 10]++;
    }

    for(int i = 1;i<10; i++){
        count[i] += count[i-1];
    }

    for(int i = n-1; i >= 0; i--){
        int digit = (arr[i] / exp) % 10;
        result[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for(int i = 0; i<n; i++){
        arr[i] = result[i];
    }
}

void radixSort(int arr[],int n){
    int m = *(max_element(arr,arr+n));
    for(int exp = 1; m / exp > 0 ; exp *= 10){
        countSort(arr,n,exp);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[] = {237,146,254,348,152,163,235,48,36,62};
    int n =  sizeof(arr) / sizeof(arr[0]);

    radixSort(arr,n);

    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}