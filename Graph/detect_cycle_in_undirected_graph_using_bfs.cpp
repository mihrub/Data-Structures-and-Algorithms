#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

vector<int> adjacency_list[1005];
bool visited[105];
int par[105];
bool cycle;

void breadth_first_search(int source){
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while(!q.empty()){
        int parent = q.front();
        q.pop();
        for(int child : adjacency_list[parent]){

            if(visited[child] && par[parent] != child){
                cycle = true; 
           }

            if(!visited[child]){
                q.push(child);
                visited[child] = true;
                par[child] = parent;
            }
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
    memset(par,-1,sizeof(par));
    cycle = false;

    for(int i = 0; i<node; i++){
        if(!visited[i]){
            breadth_first_search(i);
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