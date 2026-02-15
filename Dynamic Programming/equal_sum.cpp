#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

int arr[1005];
int dp[1005][1005];

bool equal_sum(int i,int sum){

    if(i<0){
        if(sum == 0){
            return true;
        }
        else{
            return false;
        }
    }

    if(sum >= arr[i]){
        bool op1 = equal_sum(i-1,sum-arr[i]);
        bool op2 = equal_sum(i-1,sum);
        dp[i][sum] = op1 || op2;
        return dp[i][sum];
    }
    else{
        dp[i][sum] = equal_sum(i-1,sum);
        return dp[i][sum];
    }
}

int main(){
      
    int n;
    cin >> n;
    
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += arr[i];
    }
    
    if(sum%2 == 0){
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                dp[i][j] = -1;
            }
        }
        if(equal_sum(n - 1, sum / 2)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    else{
        cout << "NO" << endl;
    }

    return 0;
}