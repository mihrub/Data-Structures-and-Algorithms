#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

vector<int> adjacency_list[1005];
bool visited[1005];

void depth_first_search(int src){
    visited[src] = true;
    for(int child : adjacency_list[src]){
        if(!visited[child]){
            depth_first_search(child);
        }
    }
}


int main(){
      
    int node,edge;
    cin >> node >> edge;

    for(int i = 0; i<edge; i++){
        int a,b; 
        cin >> a >> b;
        adjacency_list[a].push_back(b);
        adjacency_list[b].push_back(a);
    }

    memset(visited,false,sizeof(visited));
    int count = 0;

    for(int i = 0; i<node;i++){
        if(!visited[i]){
            depth_first_search(i);
            count++;
        }
    }

    cout << count << endl;

    return 0;
}