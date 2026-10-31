#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const long long INF = 1e18;

    int node, edge;
    cin >> node >> edge;

    vector<vector<long long>> adjacency_matrix(node,vector<long long>(node,INF));

    for(int i = 0; i<node; i++){
        adjacency_matrix[i][i] = 0;
    }

    while(edge--){
        long long a,b,c;
        cin >> a >> b >> c;
        adjacency_matrix[a][b] = c;
    }

    for(int k = 0; k<node; k++){
        for(int i = 0; i<node; i++){
            if(adjacency_matrix[i][k] == INF){
                continue;
            }
            for(int j = 0; j<node; j++){
                if(adjacency_matrix[k][j] == INF){
                    continue;
                }
                adjacency_matrix[i][j] = min(adjacency_matrix[i][j],adjacency_matrix[i][k] + adjacency_matrix[k][j]);
                adjacency_matrix[i][j] = max(adjacency_matrix[i][j],-INF);
            }
        }
    }

    for(int i = 0; i<node; i++){
        if(adjacency_matrix[i][i] < 0){
            cout << "Negative Cycle Exists!" << endl;
            return 0;
        }
    }

    for(int i = 0; i<node; i++){
        for(int j = 0; j<node; j++){
            if(adjacency_matrix[i][j] == INF){
                cout << "INFINITY" << " ";
            }
            else{
                cout << adjacency_matrix[i][j] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}