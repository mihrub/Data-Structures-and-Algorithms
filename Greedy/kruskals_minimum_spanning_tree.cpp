// Minimum Spanning Tree - Kruskal's Algorithm

/*

5 7
0 1 2
2 4 4
0 3 3
1 4 5
0 2 3
1 2 7
4 3 6

*/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

int parent[1005];
int group_size[1005];

int find(int node){ 
    if(parent[node] == -1){
        return node;
    }
    int leader = find(parent[node]);
    parent[node] = leader;
    return leader;
}

void dsu_union(int node1,int node2){
    int leader1 = find(node1);
    int leader2 = find(node2);
    if(group_size[leader1] >= group_size[leader2]){
        parent[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else{
        parent[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

class Edge{
public:
    int a,b,c;
    Edge(int a,int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

bool cmp(Edge l, Edge r){
    return l.c < r.c;
}

int main(){

    int node,edge;
    cin >> node >> edge;
      
    vector<Edge> edge_list;

    while(edge--){
        int a,b,c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a,b,c));
    }

    sort(edge_list.begin(),edge_list.end(),cmp);

    memset(parent,-1,sizeof(parent));
    fill(group_size, group_size + 1005, 1);

    int cost = 0;

    for(auto ed : edge_list){
        int parA = find(ed.a);
        int parB = find(ed.b);

        if(parA != parB){
            dsu_union(ed.a,ed.b);
            cost += ed.c;
        }
    }

    cout << cost << endl;


    return 0;
}