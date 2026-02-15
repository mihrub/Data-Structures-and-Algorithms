#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
using namespace std;

vector<pair<int,int>> adjacency_list[105];
int dis[105];

void dijkstra(int source){  // Time Complexity -  O(V*log(V) + E*log(V))
                           //                  -  O((V+E) * log(V))
                          //                   -  O((E+E) * log(V))  // Always E>V 
                         //                    -  O(2E * log(V))
                        //                     -  O(E * log(V))     // ignoring constants

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,source});
    dis[source] = 0;

    while(!pq.empty()){

        pair<int,int> par = pq.top();
        int par_node = par.second;
        int par_dis = par.first;
        pq.pop();

        for(auto child : adjacency_list[par_node]){

            int child_node = child.first;
            int child_dis = child.second;

            if(par_dis + child_dis < dis[child_node]){
                dis[child_node] = par_dis + child_dis;
                pq.push({dis[child_node],child_node});
            }
        }
    }
}

int main(){
      
    int node,edge;
    cin >> node >> edge;

    while(edge--){
        int a,b,c;
        cin >> a >> b >> c;
        adjacency_list[a].push_back({b,c});
        adjacency_list[b].push_back({a,c});
    }

    for(int i = 0; i<node; i++){
        dis[i] = INT_MAX;
    }

    dijkstra(0);

    for(int i = 0; i<node; i++){
        cout << dis[i] << " ";
    }

    

    return 0;
}