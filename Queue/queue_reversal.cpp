#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
using namespace std;

void queue_reversal(queue<int> &q){
    stack<int> s;

    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

int main(){

    int n;
    cin >> n;
    queue<int> q;

    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        q.push(x);
    }

    queue_reversal(q);

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
      
    return 0;
}