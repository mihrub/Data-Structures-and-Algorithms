#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

vector<int> adjacency_list[105];
bool visited[105];
int parent[105];
bool cycle;

void depth_first_search(int source){
    visited[source] = true;
    for(int child : adjacency_list[source]){
        if(visited[child] && parent[source] != child){
            cycle = true;
        }
        if(!visited[child]){
            parent[child] = source;
            depth_first_search(child);
        }
    }
}

int main(){
      
    int node,edge;
    cin >> node >> edge;

    while(edge--){
        int a,b;
        cin >> a >> b;
        adjacency_list[a].push_back(b);
        adjacency_list[b].push_back(a);
    }

    memset(visited,false,sizeof(visited));
    memset(parent,-1,sizeof(parent));
    cycle = false;

    for(int i = 0; i<node; i++){
        if(!visited[i]){
            depth_first_search(i);
        }
    }

    for(int i = 0; i<node; i++){
        cout << i << " -> " << parent[i] << endl;
    }

    if(cycle){
        cout << "Cycle Detected" << endl;
    }
    else{
        cout << "No Cycle" << endl;
    }


    return 0;
}