/*
Input : 

Cycle:

4 4
0 1 5
1 2 3
2 3 2
3 1 -6

No Cycle:

4 4
0 1 5
1 2 3
2 3 2
1 3 -6

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

vector<Edge> edge_list;
int node,edge;
int dis[1005];
                              // Time Complexity - O(V*E)
void bellman_ford_cycle(){   // Detect Cycle for negative weighted graph (Limitation of Dijkstra)
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

    bool cycle = false;

        for(auto it : edge_list){
            int a = it.a;
            int b = it.b;
            int c = it.c;
            if(dis[a] != INT_MAX && dis[a] + c < dis[b]){
                cycle = true;
                break;
            }
    }

    if(cycle){
        cout << "Cycle Detected For negative weighted graph" << endl;
    }
    else{
        for(int i = 0; i<node; i++){
            cout << i << " -> " << dis[i] << endl;
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

    dis[0] = 0;

    bellman_ford_cycle();

    return 0;
}