#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

int dp[50];

int fibo(int n){
    if(n == 1 || n == 2){
        return n;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = fibo(n-1)+ fibo(n-2);
    return dp[n];
}

int main(){

    memset(dp,-1,sizeof(dp));
      
    int n;
    cin >> n;

    cout << fibo(n) << endl;

    return 0;
}