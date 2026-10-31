#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

bool isSafe(vector<string> &board, int row, int column, int n){   // O(n)
    // Horizontal
    for(int j = 0; j<n; j++){
        if(board[row][j] == 'Q'){
            return false;
        }
    }
    // Vertical
    for(int j = 0; j<n; j++){
        if(board[j][column] == 'Q'){
            return false;
        }
    }
    // Left Diagonal
    for(int i = row, j = column; i>=0 && j>=0; i--,j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    // Right Diagonal
    for(int i = row, j = column; i>=0 && j<n; i--,j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}

void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans){   // O(n!)
    if(row == n){
        ans.push_back({board});
        return;
    }
    for(int j = 0; j<n; j++){
        if(isSafe(board,row,j,n)){
            board[row][j] = 'Q';
            nQueens(board,row+1,n,ans);
            board[row][j] = '.';
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> board(n,string(n,'.'));
    vector<vector<string>> ans;

    nQueens(board,0,n,ans);

    for(auto x: ans){
        for(auto it : x ){
            cout << it << " ";
            cout << endl;
        }
        cout << endl;
    }
    
    return 0;
}