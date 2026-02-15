#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<cstring>
using namespace std;

vector<pair<int,int>> adjacency_list[105];
int dis[105];

void dijkstra(int source){   // Time Complexity - O(V*E) for Dijkstra Naive Approach
    queue<pair<int,int>> q;
    q.push({source,0});
    dis[source] = 0;
    while(!q.empty()){
        pair<int,int> par = q.front();
        int par_node = par.first;
        int par_dis = par.second;
        q.pop();
        for(auto child : adjacency_list[par_node]){
            int child_node = child.first;
            int child_dis = child.second;

            if(par_dis + child_dis < dis[child_node]){
                dis[child_node] = par_dis + child_dis;
                q.push({child_node,dis[child_node]});
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

    // for(int i = 0; i<node; i++){
    //     cout << dis[i] << " ";
    // }
    // cout << endl;

    dijkstra(0);

    for(int i = 0; i<node; i++){
        cout << i << " -> " << dis[i] << endl;
    }

    return 0;
}