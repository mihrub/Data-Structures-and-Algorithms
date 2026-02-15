#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
using namespace std;

class Stack{
    queue<int> q;
    queue<int> qq;
public:
    void push(int val){
        while(!q.empty()){
            qq.push(q.front());
            q.pop();
        }
        q.push(val);
        while(!qq.empty()){
            q.push(qq.front());
            qq.pop();
        }
    }   
    void pop(){
        if(!q.empty())
            q.pop();
        else    
            cout << "Stack is Empty" << endl;    
    }
    int top(){  
        return q.front();
    }
    bool empty(){   
        return q.size() == 0;
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
    s.push(9);
    s.push(10);
    
    cout << "Top : " << s.top() << endl;
    cout << "Empty : " << s.empty() << endl;
    cout << "Size : " << s.size() << endl;

    s.pop();

    cout << "Top : " << s.top() << endl;
    cout << "Size : " << s.size() << endl;

    while(!s.empty()){
        cout << s.top() <<  " ";
        s.pop();
    }
    cout << endl;

    cout << "Empty : " << s.empty() << endl;

    return 0;
}