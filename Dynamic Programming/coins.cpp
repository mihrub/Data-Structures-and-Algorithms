//  Coins (AtCoder DP Contest - Problem I)
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

long double dp[3001][3001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

	int n;
	cin >> n;

	vector<long double> p(n);

	for(int i = 0; i < n; ++i){
        cin >> p[i];
    }

	int leastHeads = n / 2 + 1;

	for(int i = 0; i <= n; ++i){
		dp[i][0] = 1;
	}

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= leastHeads; ++j) {
			dp[i][j] = dp[i - 1][j - 1] * p[i - 1] + dp[i - 1][j] * (1 - p[i - 1]);
		}
	}

	cout << fixed << setprecision(10) << dp[n][leastHeads] << endl;
    return 0;
}