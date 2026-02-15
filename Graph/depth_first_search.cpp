/*
Input:

7 7

0 2
2 4
0 1
1 5
1 3
0 3
3 6

0

*/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

vector<int> adjacency_list[105];
bool visited[1005];

void depth_first_search(int source){
    cout << source << " ";
    visited[source] = true;
    for(int child : adjacency_list[source]){
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

    int source;
    cin >> source;

    depth_first_search(source);
    

    return 0;
}