#include<iostream>
#include<algorithm>
#include<vector>
#include<limits>
#include<queue>
using namespace std;

int primMST(int n,vector<vector<pair<int,int>>> &adj){
    vector<int> key(n,INT_MAX);
    vector<bool> inMST(n,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    key[0] = 0;
    pq.push({0,0});
    int totalCost = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(inMST[u]){
            continue;
        }
        inMST[u] = true;
        totalCost += key[u];

        for(auto &[v,weight] : adj[u]){
            if(!inMST[v] && weight < key[v]){
                key[v] = weight;
                pq.push({key[v],v});
            }
        }
    }
    return totalCost;
}

int main(){

    int n,e;
    cin >> n >> e;

    vector<vector<pair<int,int>>> adj(n);
    for(int i = 0; i<e; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    cout << primMST(n,adj) << endl;
    
    return 0;
}