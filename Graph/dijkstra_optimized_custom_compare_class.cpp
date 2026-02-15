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
#include<queue>
using namespace std;

class Compare{
public:
    bool operator()(pair<int,int> p , pair<int,int> q){
        return p.second > q.second;
    }
};

vector<pair<int,int>> adjacency_list[105];
int dis[105];

void dijkstra(int source){

    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;

    pq.push({source,0});
    dis[source] = 0;

    while(!pq.empty()){

        pair<int,int> par = pq.top();
        int par_node = par.first;
        int par_dis = par.second;
        pq.pop();

        for(auto child : adjacency_list[par_node]){
            int child_node = child.first;
            int child_dis = child.second;

            if(par_dis + child_dis < dis[child_node]){
                dis[child_node] = par_dis + child_dis;
                pq.push({child_node,dis[child_node]});
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