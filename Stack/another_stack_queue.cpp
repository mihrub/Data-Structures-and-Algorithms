/*
Question: Take a queue of size N as input. You need to copy those elements in another queue in reverse order.
You might use stack here. You should use STL to solve this problem. 
After copying in another queue, print the elements of that queue.


Sample Input
5
10 20 30 40 50

Sample Output
50 40 30 20 10

*/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<stack>
#include<queue>
using namespace std;
int main(){
      
    queue<int> q;
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        q.push(x);
    }
    
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}