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

    vector<pair<int,int>> edge_list;

    for(int i = 0; i<edge; i++){
        int a,b;
        cin >> a >> b;
        edge_list.push_back({a,b});
    }

    for(pair<int,int> p : edge_list){
        cout << p.first << " " << p.second << endl;
    }
    
    return 0;
}