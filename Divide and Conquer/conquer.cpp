#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

void conquer(int a[],int b[],int n,int m){      // Time Complexity - O(N)

    int c[n+m];
    int i = 0, j = 0, current = 0;

    while(i<n && j<m){
        if(a[i] > b[j]){
            c[current++] = b[j++];
        }
        else{
            c[current++] = a[i++];
        }
    }

    while(i<n){
        c[current++] = a[i++];
    }
    
    while(j<m){
        c[current++] = b[j++];
    }

    for(int k = 0; k<n+m; k++){
        cout << c[k] << " ";
    }

    cout << endl;
}

int main(){

    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    int m;
    cin >> m;

    int b[m];
    for(int i = 0; i<m; i++){
        cin >> b[i];
    }

    conquer(a,b,n,m);


    return 0;
}