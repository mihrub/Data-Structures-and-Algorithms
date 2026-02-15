#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
int main(){
      
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    
    int a = 0;
    for(int i =0; i<n; i++){
        a = max(a,arr[i]);
    }

    cout << a << endl;

    return 0;
}