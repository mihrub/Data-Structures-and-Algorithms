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
using namespace std;
int main(){
      
    int node,edge;
    cin >> node >> edge;

    vector<int> adjacency_list[node];

    for(int i = 0; i<edge; i++){
        int a,b;
        cin >> a >> b;
        adjacency_list[a].push_back(b);
        adjacency_list[b].push_back(a);
    }

    for(int i = 0; i<node; i++){
        cout << "Index = " << i << " -> ";
        for(int x : adjacency_list[i]){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}