
// https://cses.fi/problemset/task/1672

#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
int main(){
      
    int n,m,q;
    cin >> n >> m >> q;

    long long adjacency_matrix[n+5][n+5];
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(i == j){
                adjacency_matrix[i][j] = 0;
            }
            else{
                adjacency_matrix[i][j] = LONG_LONG_MAX;
            }
        }
    }

    while(m--){
        long long a,b,c;
        cin >> a >> b >> c;
        adjacency_matrix[a][b] = min(adjacency_matrix[a][b],c);
        adjacency_matrix[b][a] = min(adjacency_matrix[b][a],c);
    }

    for(int k = 1; k<=n; k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(adjacency_matrix[i][k] != LONG_LONG_MAX && adjacency_matrix[k][j] != LONG_LONG_MAX && (adjacency_matrix[i][k] + adjacency_matrix[k][j] < adjacency_matrix[i][j])){
                    adjacency_matrix[i][j] =  adjacency_matrix[i][k] + adjacency_matrix[k][j];
                }
            }
        }
    }

    while(q--){
        int a,b;
        cin >> a >> b;
        if(adjacency_matrix[a][b] == LONG_LONG_MAX){
            cout << -1 << endl;
        }
        else{
            cout << adjacency_matrix[a][b] << endl;
        }
    }
    
    return 0;
}