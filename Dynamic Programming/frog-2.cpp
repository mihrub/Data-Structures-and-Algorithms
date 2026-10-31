// Frog 2 (AtCoder DP Contest - Problem B)
#include<iostream>
#include<algorithm>
#include<cmath>
#include<climits>
#include<vector>
#include<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    vector<int> dp(n + 1, INT_MAX);
    dp[1] = 0;

    for (int i = 2; i <= n; i++){
        for (int j = max(1, i - k); j < i; j++){
            dp[i] = min(dp[i], dp[j] + abs(v[i] - v[j]));
        }
    }

    cout << dp[n] << endl;
    return 0;
}