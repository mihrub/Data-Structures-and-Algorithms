#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

int arr[1005];
int dp[1005][1005];

int count_sum(int i, int sum){

    if(i<0){
        if(sum == 0){
            return 1;
        }
        else{
            return 0;
        }
    }

    if(dp[i][sum] != -1){
        return dp[i][sum];
    }

    if(sum >= arr[i]){
        int op1 = count_sum(i-1,sum-arr[i]);
        int op2 = count_sum(i-1,sum);
        dp[i][sum] = op1 + op2;
        return dp[i][sum];
    }
    else{
        dp[i][sum] = count_sum(i-1,sum);
        return dp[i][sum];
    }
}

int main(){
      
    int n;
    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    int sum;
    cin >> sum;

    for(int i = 0; i<=n; i++){
        for(int j = 0; j<= sum; j++){
            dp[i][j] = -1;
        }
    }

    cout << count_sum(n-1,sum) << endl;


    return 0;
}