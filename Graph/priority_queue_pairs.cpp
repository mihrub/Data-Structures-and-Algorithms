#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
using namespace std;

class Compare{
public:
    bool operator()(pair<int,int>p, pair<int,int> q){
        return p.second > q.second;
    }
};

int main(){
      
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
    
    pq.push({10,1});
    pq.push({5,2});

    cout << pq.top().first << " " << pq.top().second << endl;

    return 0;
}