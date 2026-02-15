#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

int n,m;
char grid[105][105];
bool visited[105][105];
vector<pair<int,int>> vp = {{0,-1},{0,1},{-1,0},{1,0}};

bool valid(int i,int j){
    if(i<0 || i >= n || j<0 || j >= m){
        return false;
    }
    else{
        return true;
    }
}

void depth_first_search(int si,int sj){
    
    cout << si << " " << sj << endl;
    visited[si][sj] = true;

    for(int i = 0; i<4; i++){

        int ci = si + vp[i].first;
        int cj = sj + vp[i].second;

        if(valid(ci,cj) && !visited[ci][cj]){
            depth_first_search(ci,cj);
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

    int si,sj;
    cin >> si >> sj;

    memset(visited,false,sizeof(visited));

    depth_first_search(si,sj);

    return 0;
}