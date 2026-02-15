#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class Queue{
    stack<int> s;
    stack<int> ss;
public:
    void push(int val){
        while(!s.empty()){
            ss.push(s.top());
            s.pop();
        }
        s.push(val);
        while(!ss.empty()){
            s.push(ss.top());
            ss.pop();
        }
    }
    void pop(){
        if(!s.empty())
            s.pop();
        else
            cout << "Queue is Empty" << endl;    
    }
    int front(){
        return s.top();
    }
    bool empty(){
        return s.size() == 0;
    }
    int size(){
        return s.size();
    }

};

int main(){
      
    Queue q;

    q.push(1);
    q.push(2);    
    q.push(3);   
    q.push(4);   
    q.push(5);
    q.push(6);  
    
    cout << "Front : " << q.front() << endl;
    cout << "Size : " << q.size() << endl;
    cout << "Empty : " << q.empty() << endl;

    q.pop();

    cout << q.front() << endl;

    cout << "Size : " << q.size() << endl;

    q.push(12);
    cout << q.front() << endl;

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    cout << "Empty : " << q.empty() << endl;
    return 0;
}