/*
Input :

4 5
0 1 3
0 2 6
1 2 2
1 3 5
2 3 4

*/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
int main(){
      
    int node,edge;
    cin >> node >> edge;

    int adjacency_matrix[node][node];

    for(int i = 0; i<node; i++){
        for(int j = 0; j<node; j++){
            if(i == j){
                adjacency_matrix[i][j] = 0;
            }
            else{
                adjacency_matrix[i][j] = INT_MAX;
            }
        }
    }

    while(edge--){
        int a,b,c;
        cin >> a >> b >> c;
        adjacency_matrix[a][b] = c;
    }

    for(int k = 0; k<node; k++){
        for(int i = 0; i<node; i++){
            for(int j = 0; j<node; j++){
                if(adjacency_matrix[i][k] != INT_MAX && adjacency_matrix[k][j] != INT_MAX && (adjacency_matrix[i][k] + adjacency_matrix[k][j] < adjacency_matrix[i][j]))
                    adjacency_matrix[i][j] = adjacency_matrix[i][k] + adjacency_matrix[k][j];
            }
        }
    }

    // Time Complexity = O(V^3)

    for(int i = 0; i<node; i++){
        for(int j = 0; j<node; j++){
            if(adjacency_matrix[i][j] == INT_MAX)
                cout << "INFINITY" << " ";
            else
                cout << adjacency_matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}