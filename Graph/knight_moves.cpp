/*
You will be given a chessboard of N * M size. You can move anywhere in the chessboard freely. You will be given two cells - the knight's cell K (Ki and Kj ), and the queen's cell  Q(Qi and Qj ).
You need to tell the minimum number of steps for the knight to attack the queen if the queen doesn't move.

A knight move in 8 directions. The directions are given below:image

Input Format

First line will contain , the number of test cases.
First line of each test case will contain N and M .
Second line of each test case will contain Ki and Kj.
Third line of each test case will contain  Qi and Qj.

Output Format

Output the minimum number of steps for the knight to reach the queen. If you can't reach to queen, print -1.

Sample Input 0

4
8 8
0 0
7 7
5 6
0 1
0 1
4 4
0 0
0 1
2 2
0 0
0 1

Sample Output 0

6
0
3
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

int n,m;
int grid[105][105];
bool visited[105][105];
int level[105][105];
vector<pair<int,int>> vp = {{-2,1},{-2,-1},{2,1},{2,-1},{-1,2},{1,2},{-1,-2},{1,-2}};

int valid(int i,int j){
    if(i < 0 || i >= n || j < 0 || j >= m){
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

        for(int i = 0; i<8; i++){

            int ci = par_i + vp[i].first;
            int cj = par_j + vp[i].second;

            if(!visited[ci][cj] && valid(ci,cj)){
                visited[ci][cj] = true;
                qp.push({ci,cj});
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main(){

    int t;
    cin >> t;

    while(t--){
      
    cin >> n >> m;

    int si,sj,di,dj;
    cin >> si >> sj >> di >> dj;

    grid[si][sj] = 1;
    grid[di][dj] = 1;

    memset(grid,0,sizeof(grid));

    memset(visited,false,sizeof(visited));
    memset(level,-1,sizeof(level));

    breadth_first_search(si,sj);

    cout << level[di][dj] << endl;
}      
    return 0;
}