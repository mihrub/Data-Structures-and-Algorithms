/*
Input:

5 8

0 1 10
1 2 1
0 2 7
0 3 4
2 3 1
3 4 5
1 4 3
2 4 5

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

    vector<pair<int,int>> adjacency_list[node];

    while(edge--){
        int a,b,c;
        cin >> a >> b >> c;
        adjacency_list[a].push_back({b,c});
        adjacency_list[b].push_back({a,c});
    }

    for(int i = 0; i<node; i++){
        cout << i << " -> ";
        for(pair<int,int> p : adjacency_list[i]){
            cout << p.first << " " <<  p.second << ", ";
        }
        cout << endl;
    }

    return 0;
}