#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

void check_node(int source,int destination,vector<int>adjacency_list[],int edge){
    bool visited[edge+1];
    memset(visited,false,sizeof(visited));
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while(!q.empty()){
        int parent = q.front();
        q.pop();
        for(int child : adjacency_list[parent]){
            if(!visited[child]){
                q.push(child);
                visited[child] = true;

            }
        }
    }
    if(visited[destination]){
        cout << "Node is connected" << endl;
    }
    else{
        cout << "Not Connected" << endl;
    }
}


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
    
    int source,destination;
    cin >> source >> destination;
    check_node(source,destination,adjacency_list,edge);


    return 0;
}