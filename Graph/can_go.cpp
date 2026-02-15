/*
You are given an N x M sized 2D matrix that represents a map of a building. 
Each cell represents a wall, a floor or a room. 
You will be given two rooms A and B. 
You need to tell if you can go from room A to B by passing through the floors. 
You can walk left, right, up, and down through the floor cells. 
You can't pass through walls.

Input Format

The first input line has two integers N and M : the height and width of the map.
Then there are N lines of M characters describing the map. Each character is .(floor), #(wall), A or B (rooms).
Constraints

Output Format

Output YES if you can go from room A to B , NO otherwise.

Sample Input:

5 8
########
#.A#...#
#.##.#B#
#......#
########

Sample Output:
YES

*/


#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

int n,m;
bool visited[1005][1005];
int level[1005][1005];
char grid[1005][1005];
vector<pair<int,int>> vp = {{0,1},{0,-1},{1,0},{-1,0}};

bool valid(int i,int j){
    if(i<0 || i>=n || j<0 || j>=m){
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
    level[si][sj] = 0;
    while(!qp.empty()){
        pair<int,int> p = qp.front();
        int par_i = p.first;
        int par_j = p.second;
        qp.pop();
        for(int i = 0; i<4; i++){
            int ci = par_i + vp[i].first;
            int cj = par_j + vp[i].second;
            if((!visited[ci][cj] && valid(ci,cj) && grid[ci][cj] == '.') || (grid[ci][cj] == 'A' || grid[ci][cj] == 'B')){
                qp.push({ci,cj});
                visited[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    int si=0,sj=0,di=0,dj=0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> grid[i][j];
        }
    }
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == 'A'){
                si = i;
                sj = j;
            }
            else if(grid[i][j] == 'B'){
                di = i;
                dj = j;
            }
        }
    }    

    memset(visited,false,sizeof(visited));
    memset(level,-1,sizeof(level));

    breadth_first_search(si,sj);

    if(level[di][dj] != -1){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}
