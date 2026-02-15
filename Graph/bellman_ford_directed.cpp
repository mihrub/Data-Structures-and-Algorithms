/*
Input:

4 4
0 2 5
0 3 12
2 1 2
1 3 3

*/


#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

class Edge{
public:
    int a,b,c;
    Edge(int a,int b,int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int node,edge;
vector<Edge> edge_list;
int dis[1005];

void bellman_ford(){   // Time Complexity = O(V*E)
    for(int i = 0; i<node-1; i++){
        for(auto it : edge_list){
            int a = it.a;
            int b = it.b;
            int c = it.c;
            if(dis[a] != INT_MAX && dis[a] + c < dis[b]){
                dis[b] = dis[a] + c;
            }
        }
    }
}

int main(){
      
    cin >> node >> edge;

    while(edge--){
        int a,b,c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a,b,c));
    }

    for(int i = 0; i<node; i++){
        dis[i] = INT_MAX;
    }

    dis[0] = 0;  // Distance of Source to Source is equal to 0

    bellman_ford();

    for(int i = 0; i<node;i++){
        cout << i << " -> " << dis[i] << endl;
    }

    return 0;
}