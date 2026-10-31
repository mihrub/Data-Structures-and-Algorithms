#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

void helper(vector<vector<int>> &mat,int r, int c, string path,vector<string> &ans , vector<vector<bool>> &visited){
    int n = mat.size();
    if(r < 0 || c < 0 || r>=n || c>=n || mat[r][c] == 0 || visited[r][c] == true){
        return;
    }
    if(r == n-1 && c == n-1){
        ans.push_back(path);
        return;
    }

    visited[r][c] = true;

    helper(mat,r-1,c,path+"U",ans,visited);
    helper(mat,r,c+1,path+"R",ans,visited);
    helper(mat,r+1,c,path+"D",ans,visited);
    helper(mat,r,c-1,path+"L",ans,visited);

    visited[r][c] = false;
}

vector<string>findPath(vector<vector<int>> &mat){
    int n = mat.size();
    string path = "";
    vector<string> ans;
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    helper(mat,0,0,path,ans,visited);
    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> mat = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};

    auto x = findPath(mat);

    for(auto it : x){
        cout << it << endl;
    }
    
    return 0;
}