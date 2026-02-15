#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

void shortest_distance(int source,int destination,vector<int>adjacency_list[],int node){
    
    bool check_node[node+1];
    memset(check_node,false,sizeof(check_node));

    int level[node+1];
    memset(level,-1,sizeof(level));

    queue<int> q;
    q.push(source);
    check_node[source] = true;
    level[source] = 0;

    while(!q.empty()){
        int parent = q.front();
        q.pop();
        for(int child : adjacency_list[parent]){
            if(!check_node[child]){
                check_node[child] = true;
                level[child] = level[parent] + 1;
            }
        }   
    }
    
    cout << "Shortest Distance : " << level[destination] << endl;

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

    shortest_distance(source,destination,adjacency_list,edge);


    return 0;
}