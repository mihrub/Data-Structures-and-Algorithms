/*
Input :
6 8

0 2
0 4
0 5
1 4
1 5
2 3
2 4
4 5

Check - graph.png

*/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

// Time Complexity O(node + edge)   or   Time Complexity O(vertex + edge)
// Space Complexity O(node)

void breadth_first_search(vector<int> adjacency_list[],int edge){
    bool visited[edge+1];
    memset(visited,false,sizeof(visited));
    queue<int> q;
    q.push(0);
    visited[0] = true;

    while(!q.empty()){    // O(N)
        int parent = q.front();
        q.pop();
        cout << parent << " ";

        for(int child : adjacency_list[parent]){   // O(E)
            if(!visited[child]){
                q.push(child);
                visited[child] = true;
            }
        }
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

    breadth_first_search(adjacency_list,edge);


    return 0;
}