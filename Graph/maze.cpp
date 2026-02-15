/*
Rezia is trapped in a 2D maze of N * M size, starting at position R, and her goal is to reach the exit marked by D. 
The maze contains blocks represented by # , and she can only traverse through cells marked with dots (.). 
As she need to escape as early as possible, we need to determine the path she will follow.

Place an X in each cell representing Rezia's route to exit the maze. If there is no viable path for her to exit, leave the maze unchanged.

Note: Rezia can move in four directions – right, left, up, and down. 
It is crucial to adhere to the specified order: attempting right first, then left, followed by up, and finally down.

Input Format

First line will contain N and M.
Next you will be given the 2D matrix.

Output Format

Output the final maze with marked X indicating the path she will follow.

Sample Input 0:

5 6
...D.#
.##..#
....#.
.R#...
.#.##.

Sample Output 0:
...D.#
.##X.#
.XXX#.
.R#...
.#.##.

Sample Input 1:

5 6
...D.#
.R...#
....#.
..#...
.#.##.

Sample Output 1:

...D.#
.RXX.#
....#.
..#...
.#.##.

Sample Input 2:

5 6
...D.#
.....#
.##.#.
.R#...
.#.##.

Sample Output 2:

...D.#
XXXX.#
X##.#.
XR#...
.#.##.

Sample Input 3:

5 6
...D.#
.....#
###.#.
.R#...
.#.##.

Sample Output 3:

...D.#
.....#
###.#.
.R#...
.#.##.

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
pair<int,int> parent_node[1005][1005];

vector<pair<int,int>> d = {{0,1},{0,-1},{-1,0},{1,0}};
int n,m,s1,s2,d1,d2;

bool valid(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m)
        return false;
    return true;
}

void bfs(int si,int sj){

    queue<pair<int,int>> qp;
    qp.push({si,sj});
    vis[si][sj] = true;
    while(!qp.empty()){

        pair<int,int> p = qp.front();
        int par_i = p.first;
        int par_j = p.second;

        qp.pop();

        for(int i = 0; i<4; i++){

            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;

            if(!vis[ci][cj] && valid(ci,cj) && (grid[ci][cj] == '.' || grid[ci][cj] == 'D' || grid[ci][cj] == 'R')){
                vis[ci][cj] = true;
                qp.push({ci,cj});
                parent_node[ci][cj] = p;
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

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] == 'R'){
                s1 = i;
                s2 = j;
            }
            else if(grid[i][j] == 'D'){
                d1 = i;
                d2 = j;
            }
        }
    }
    
    memset(vis,false,sizeof(vis));
    memset(parent_node,-1,sizeof(parent_node));

    bfs(s1,s2);
    
    vector<pair<int,int>> path;
    pair<int,int> newNode({d1,d2});


if(vis[d1][d2]){
    while(true){
        if(newNode.first == s1 && newNode.second == s2){
            break;
        }
        path.push_back(newNode);
        int ni = newNode.first;
        int nj = newNode.second;
        newNode = parent_node[ni][nj];
    }
}

    int size = path.size();

for(int i = 0; i<size; i++){
    int a = path[i].first;
    int b = path[i].second;
    grid[a][b] = 'X';
}

    grid[s1][s2] = 'R';
    grid[d1][d2] = 'D';

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout << grid[i][j];
        }
        cout << endl;
    }     

    return 0;
}