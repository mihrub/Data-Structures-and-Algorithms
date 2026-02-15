#include<iostream>
#include<algorithm>
using namespace std;
int main(){

    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i<n ; i++){
        cin >> arr[i];
    }

    int pos,val;
    cin >> pos >> val;

    int crr[n+1];

    for(int i = 0; i<pos; i++){
        crr[i] = arr[i];
    }
        crr[pos] = val;

    int i = pos+1;
    int j = pos;
    
    while(j<=n){
        crr[i++] = arr[j++];
    }

    arr[pos] = val;

    for(int i = 0; i<=n; i++){
        cout << crr[i] << " ";
    }
 
    return 0;
}