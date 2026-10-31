//  Longest Path (AtCoder DP Contest - Problem G)
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

vector<int> adj[100005];
int dp[100005];
bool visited[100005];

int longestPath(int v){

    if(visited[v]){
        return dp[v];
    }

    visited[v] = true;
    int best = 0;

    for(int u : adj[v]){
        best = max(best, longestPath(u) + 1);
    }
    dp[v] = best;

    return dp[v];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v,e;
    cin >> v >> e;

    while(e--){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    int ans = 0;
    for(int i = 1; i <= v; i++){
        ans = max(ans, longestPath(i));
    }

    cout << ans << endl;

    return 0;
}