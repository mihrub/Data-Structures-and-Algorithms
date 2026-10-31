//  Grid 1 (AtCoder DP Contest - Problem H)
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

const long long MOD = 1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;

    vector<string> grid(h + 1);
    for(int i = 1; i <= h; i++){
        cin >> grid[i];
        grid[i] = " " + grid[i]; 
    }

    vector<vector<long long>> dp(h + 1, vector<long long>(w + 1, 0));
    dp[1][1] = 1;

    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(i == 1 && j == 1)
                continue;

            if(grid[i][j] == '#'){
                dp[i][j] = 0;
                continue;
            }

            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }

    cout << dp[h][w] << endl;
    return 0;
}