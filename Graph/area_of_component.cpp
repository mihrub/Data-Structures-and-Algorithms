/*
You will be given a 2D matrix of size N * M  which will contain only dot(.) and minus(-) where dot(.) means you can go in that cell and minus(-) means you can't.

You can move in only 4 directions (Up, Down, Left and Right).

The area of a component is the number of dots(.) in that component that can be accessible. You need to tell the minimum area of all available components.

Note: If there are no components, print -1.

Input Format

First line will contain N and M.
Next you will be given the 2D matrix.

Output Format

Output the minimum area.

Sample Input 0:
6 5
..-..
..-..
-----
.-...
.----
.....

Sample Output 0:
3

Sample Input 1:
3 3
---
---
---

Sample Output 1:
-1

*/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

bool vis[1005][1005];
char grid[1005][1005];
vector<pair<int,int>> d = {{0,-1},{0,1},{-1,0},{1,0}};
int n,m,cnt,mn;

bool valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m)
        return false;
    return true;
}

void dfs(int si, int sj){
    vis[si][sj] = true;
    cnt++;
    for(int i=0;i<4;i++){
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj] == '.')
            dfs(ci,cj);
    }
}

int main(){

    cin >> n >> m;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> grid[i][j];
        }
    }
    
    memset(vis,false,sizeof(vis));
    mn = INT_MAX;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == '.'){
                cnt = 0;
                dfs(i,j);
                mn = min(cnt,mn);
        }
    }
}

    if(mn == INT_MAX){
        cout << -1 << endl;
    }
    else{
        cout << mn << endl;
    }

    return 0;
}