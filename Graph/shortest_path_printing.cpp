#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

void shortest_path_print(int source,int destination,vector<int>adjacency_list[],int node){

    bool visited[node+1];
    int level[node+1];
    int parent_node[node+1];
    memset(visited,false,sizeof(visited));
    memset(level,-1,sizeof(level));
    memset(parent_node,-1,sizeof(parent_node));

    queue<int> q;
    q.push(source);
    visited[source] = true;

    while(!q.empty()){
        int parent = q.front();
        q.pop();

        for(int child : adjacency_list[parent]){
            if(!visited[child]){
                level[child] = level[parent] + 1;
                visited[child] = true;
                parent_node[child] = parent;
            }            
        }
    }

    for(int i = 0; i<node+1; i++){
        cout << i << " " << parent_node[i] << endl;
    }

    vector<int> path;
    int newNode = destination;

    while(newNode != -1){
        path.push_back(newNode);
        newNode = parent_node[newNode];
    }

    reverse(path.begin(),path.end());

    for(int x : path){
        cout << x << " ";
    }
    cout << endl;

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

    shortest_path_print(source,destination,adjacency_list,edge);    


    return 0;
}