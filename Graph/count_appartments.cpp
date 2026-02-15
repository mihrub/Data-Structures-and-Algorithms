/*
You are given an N x M sized 2D matrix that represents a map of a building. 
Each cell represents a wall or a room. The connected rooms are called apartments. 
Your task is to count the number of apartments in that building.
You can walk left, right, up, and down through the room cells. 
You can't pass through walls.

Input Format

The first input line has two integers N and M : the height and width of the map.
Then there are N lines of M characters describing the map. Each character is either .(room) or #(wall).

Output Format
Output the number of apartments

Sample Input 1:
5 8
########
#..#...#
####.#.#
#..#...#
########

Sample Output 1:
3

Sample Input 2:
6 8
.#.#####
.#.###..
#..#...#
#.##....
..##.###
#.#.##.#

Sample Output 2:
5

*/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

int n,m;
char grid[1005][1005];
bool visited[1005][1005];
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
    visited[si][sj] = true;

    for(int i = 0; i<4; i++){

        int ci = si + vp[i].first;
        int cj = sj + vp[i].second;

        if(valid(ci,cj) && !visited[ci][cj] && grid[ci][cj] == '.'){
            depth_first_search(ci,cj);
        }
    }
}


int main()
{
    cin >> n >> m;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> grid[i][j];
        }
    }

    memset(visited,false,sizeof(visited));
    int count = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(!visited[i][j] && grid[i][j] == '.'){
                depth_first_search(i,j);
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
