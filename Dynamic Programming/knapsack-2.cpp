// Knapsack 2 (AtCoder DP Contest - Problem E)
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<climits>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long a;
    cin >> n >> a;

    vector<long long> w(n);
    vector<int> v(n);
    int total = 0;

    for(int i = 0; i < n; i++){
        cin >> w[i] >> v[i];
        total += v[i];
    }

    const long long INF = LLONG_MAX / 2;
    vector<long long> dp(total + 1, INF);
    dp[0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = total; j >= v[i]; j--){
            if (dp[j - v[i]] + w[i] < dp[j]){
                dp[j] = dp[j - v[i]] + w[i];
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= total; j++){
        if (dp[j] <= a){
            ans = j;
        }
    }

    cout << ans << endl;
    return 0;
}