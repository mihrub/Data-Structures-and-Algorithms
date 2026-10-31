// Vacation (AtCoder DP Contest - Problem C)
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<array>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<array<int, 3>> hp(n);
    for (int i = 0; i < n; i++)
        cin >> hp[i][0] >> hp[i][1] >> hp[i][2];

    vector<array<int, 3>> dp(n);
    dp[0] = hp[0];

    for (int i = 1; i < n; i++){
        for (int j = 0; j < 3; j++){
            int b = 0;
            for (int k = 0; k < 3; k++){
                if (k != j)
                    b = max(b, dp[i - 1][k]);
            }
            dp[i][j] = hp[i][j] + b;
        }
    }

    cout << *max_element(dp[n - 1].begin(), dp[n - 1].end()) << endl;
    return 0;
}