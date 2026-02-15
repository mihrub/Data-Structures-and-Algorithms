/*
Input:
5 5
0 1
0 2
3 0
1 3
3 4

                0
              / \ \
            /   1  \
          /   /     2
        /   /               (connected to 3)
       3--------4 

*/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
int main(){
      
    int node,edge;
    cin >> node >> edge;

    int adjacency_matrix[node][node];
    memset(adjacency_matrix,0,sizeof(adjacency_matrix));

    for(int i = 0; i<node; i++){
        adjacency_matrix[i][i] = 1;
    }

    for(int i = 0; i<edge; i++){
        int a,b;
        cin >> a >> b;
        adjacency_matrix[a][b] = 1;
    }

    for(int i = 0; i<node; i++){
        for(int j = 0; j<node; j++){
            cout << adjacency_matrix[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}