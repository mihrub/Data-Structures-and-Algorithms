#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

bool isValid(vector<vector<int>> &grid, int r, int c, int n, int expected_value){

    if(r < 0 || c < 0 || r >= n || c >=n || grid[r][c] != expected_value){
        return false;
    }
    
    if(expected_value == n*n - 1){
        return true;
    }

    bool ans1 = isValid(grid,r-2,c+1,n,expected_value+1);
    bool ans2 = isValid(grid,r-1,c+2,n,expected_value+1);
    bool ans3 = isValid(grid,r+1,c+2,n,expected_value+1);
    bool ans4 = isValid(grid,r+2,c+1,n,expected_value+1);
    bool ans5 = isValid(grid,r+2,c-1,n,expected_value+1);
    bool ans6 = isValid(grid,r+1,c-2,n,expected_value+1);
    bool ans7 = isValid(grid,r-1,c-2,n,expected_value+1);
    bool ans8 = isValid(grid,r-2,c-1,n,expected_value+1);

    return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> grid = {{0,3,6},{5,8,1},{2,7,4}};

    bool ans = isValid(grid,0,0,grid.size(),0);

    if(ans){
        cout << "Knight Tour Possible" << endl;
    }
    else{
        cout << "Knight Tour Not Possible" << endl;
    }

    return 0;
}