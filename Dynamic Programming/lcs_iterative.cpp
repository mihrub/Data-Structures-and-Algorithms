#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<set>
using namespace std;

int lcsTable(string a, string b,vector<vector<int>> &dp){

    int m = a.size();
    int n = b.size();
    dp.assign(m+1,vector<int>(n+1,0));

    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

string printSequence(string a, string b, vector<vector<int>> &dp){

    int i = a.size();
    int j = b.size();
    string lcs = "";
    while(i > 0 && j > 0){
        if(a[i-1] == b[j-1]){
            lcs += a[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] >= dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(lcs.begin(),lcs.end());
    return lcs;
}

void printAllLCS(string a, string b, int i, int j, vector<vector<int>> &dp, string current, set<string> &allLCS){
    if(i == 0 || j == 0){
        string reversed = current;
        reverse(reversed.begin(),reversed.end());
        allLCS.insert(reversed);
        return;
    }
    if(a[i-1] == b[j-1]){
        printAllLCS(a, b, i-1, j-1, dp, current + a[i-1], allLCS);
    }
    else{
        if(dp[i-1][j] >= dp[i][j-1]){
            printAllLCS(a, b, i-1, j, dp, current, allLCS);
        }
        if(dp[i][j-1] >= dp[i-1][j]){
            printAllLCS(a, b, i, j-1, dp, current, allLCS);
        }
    }
}

int main(){

    string a, b;
    cin >> a >> b;

    vector<vector<int>> dp;
    set<string> allLCS;

    int m = a.size();
    int n = b.size();

    cout << lcsTable(a,b,dp) << endl;
    cout << printSequence(a,b,dp) << endl;
    printAllLCS(a, b, m, n, dp, "", allLCS);

    for(auto it : allLCS){
        cout << it << endl;
    }
    
    return 0;
}