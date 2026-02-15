#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

vector<int> adjacency_list[105];
bool visited[105];
bool path_visited[105];
bool cycle;

void depth_first_search(int source){
    visited[source] = true;
    path_visited[source] = true;
    for(int child : adjacency_list[source]){
        if(visited[child] && path_visited[child]){
            cycle = true;
        }
        if(!visited[child]){
            depth_first_search(child);
        }
    }
    path_visited[source] = false;
}

int main(){
      
    int node,edge;
    cin >> node >> edge;

    while(edge--){
        int a,b;
        cin >> a >> b;
        adjacency_list[a].push_back(b);
    }

    memset(visited,false,sizeof(visited));
    memset(path_visited,false,sizeof(path_visited));
    cycle = false;

    for(int i = 0; i<node; i++){
        if(!visited[i]){
            depth_first_search(i);
        }
    }

    if(cycle){
        cout << "Cycle Detected" << endl;
    }
    else{
        cout << "No Cycle" << endl;
    }

    return 0;
}