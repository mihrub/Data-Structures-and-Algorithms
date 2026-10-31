#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

string shortestCommonSupersequence(const string& X, const string& Y){
    int m = X.size(), n = Y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = (X[i - 1] == Y[j - 1]) ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string scs;
    int i = m, j = n;
    while(i > 0 && j > 0){
        if(X[i - 1] == Y[j - 1]){
            scs += X[i - 1];
            i--;
            j--;
        }
        else if(dp[i - 1][j] >= dp[i][j - 1]){
            scs += X[i - 1];
            i--;
        }
        else{
            scs += Y[j - 1];
            j--;
        }
    }

    while(i > 0){
        scs += X[i - 1]; i--;
    }

    while(j > 0){
        scs += Y[j - 1]; j--;
    }

    reverse(scs.begin(), scs.end());
    return scs;
}

int main(){

    string X, Y;
    cout << "Enter first DNA sequence: ";
    cin >> X;
    cout << "Enter second DNA sequence: ";
    cin >> Y;

    string scs = shortestCommonSupersequence(X, Y);
    cout << "Length of Shortest Common Supersequence = " << scs.size() << endl;
    cout << "Shortest Common Supersequence = " << scs << endl;

    return 0;
}
