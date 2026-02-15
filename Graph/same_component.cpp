/*
You will be given a 2D matrix of size N * M which will contain only dot(.) and minus(-) where dot(.) means you can go in that cell and minus(-) means you can't.

You can move in only 4 directions (Up, Down, Left and Right).

You will be given the indexes of two cells - S(si,sj) and D(di,dj). You need to tell if these S and D cells are in the same component or not. Same component means you can go from S to D .

Input Format

First line will contain N and M.
Next you will be given the 2D matrix.
Next line will contain Si and Sj.
Last line will contain Di and Dj.

Output Format

Output "YES" if those cell are in the same component, "NO" otherwise.

Sample Input 0:

5 4
..-.
---.
..-.
--..
....
0 1
3 2

Sample Output 0 :
NO

Sample Input 1:

5 4
....
---.
..-.
--..
....
0 1
3 2

Sample Output 1:
YES

*/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

bool vis[1005][1005];
char grid[1005][1005];
vector<pair<int,int>> d =  {{0,-1},{0,1},{-1,0},{1,0}};
int n,m;

bool valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m)
        return false;
    return true;
}

void dfs(int si, int sj){
    vis[si][sj] = true;
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
    
    int si,sj,di,dj;
    cin >> si >> sj >> di >> dj;

    dfs(si,sj);

    if(vis[di][dj]){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }   
    
    return 0;
}