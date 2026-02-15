#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

int n,m;
char grid[1005][1005];
bool visited[1005][1005];
vector<pair<int,int>> vp = {{0,1},{0,-1},{-1,0},{1,0}};

bool valid(int i,int j){
    if( i<0 || i >= n || j<0 || j >= m){
        return false;
    }
    else{
        return true;
    }
}

void breadth_first_search(int si,int sj){
    queue<pair<int,int>> qp;
    qp.push({si,sj});
    visited[si][sj] = true;
    while(!qp.empty()){
        pair<int,int> p = qp.front();
        int par_i = p.first;
        int par_j = p.second;
        qp.pop();

        cout << par_i << " " << par_j << endl;

        for(int i = 0; i<4; i++){
            int ci = par_i + vp[i].first;
            int cj = par_j + vp[i].second;
            if(valid(ci,cj) && !visited[ci][cj]){
                qp.push({ci,cj});
                visited[ci][cj] = true;
            }
        }
    }
}

int main(){
      
    cin >> n >> m;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> grid[i][j];
        }
    }

    memset(visited,false,sizeof(visited));

    int si,sj;
    cin >> si >> sj;
    breadth_first_search(si,sj);

    return 0;
}