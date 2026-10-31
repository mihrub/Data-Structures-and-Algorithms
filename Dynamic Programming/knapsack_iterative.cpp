#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

int knapsack01(int W, vector<int> weight, vector<int> value, vector<vector<int>> &dp){
    int n = weight.size();
    for(int i = 1; i<=n; i++){
        for(int w = 0; w<=W; w++){
            dp[i][w] = dp[i-1][w];
            if(weight[i-1] <= w){
                dp[i][w] = max(dp[i][w],dp[i-1][w-weight[i-1]] + value[i-1]);
            }
        }
    }
    return dp[n][W];
}

vector<int> reconstruct01(int W, vector<int> weight, vector<vector<int>> &dp){

    int n = weight.size();
    int w = W;
    vector<int> chosen;

    for(int i = n; i > 0 && w > 0 ; i--){
        if(dp[i][w] != dp[i-1][w]){
            chosen.push_back(i-1);
            w -= weight[i-1];
        }
    }
    reverse(chosen.begin(),chosen.end());
    return chosen;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,W;
    cin >> n >> W;

    vector<int> weight(n);
    vector<int> value(n);

    for(int i = 0; i<n; i++){
        cin >> weight[i] >> value[i];
    }

    vector<vector<int>> dp(n+1,vector<int>(W+1,0));

    int best = knapsack01(W,weight,value,dp);
    cout << "DP Table: " << endl;

    for(auto itr : dp){
        for(auto it : itr){
            cout << it << " ";
        }
        cout << endl;
    }

    cout << "Maximum Value : " << best << endl;

    vector<int> chosen = reconstruct01(W,weight,dp);
    cout << "Item Selected : ";
    for(auto it : chosen){
        cout << it << " ";
    }
    cout << endl;
    
    return 0;
}