#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
using namespace std;

class Stack{
    queue<int> q;
public:

    void push(int val){
        q.push(val);
    }

    void pop(){
    queue<int> q2;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(q.empty())
            break;
        q2.push(x);    
    }
    q = q2;
    }

    int top(){
        return q.back();
    }
    bool empty(){
        return q.empty();
    }
    int size(){
        return q.size();
    }

};

int main(){
      
    Stack s;
    
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);

    s.pop();

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}