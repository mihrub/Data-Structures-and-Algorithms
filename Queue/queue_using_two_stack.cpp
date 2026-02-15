#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class Queue{
    stack<int> s;
public:
    void push(int val){
        s.push(val);
    }   
    void pop(){
        stack<int> s2;
        while(!s.empty()){
            int x = s.top();
            s.pop();
            if(s.empty())
                break;
            s2.push(x);    
        }

        while(!s2.empty()){
            s.push(s2.top());
            s2.pop();
        }
    }   
    int front(){
        stack<int> s2;
        while(!s.empty()){
            s2.push(s.top());
            s.pop();
        }
        while(!s2.empty()){
            s.push(s2.top());
            s2.pop();
        }
        return s.top();
    } 
    bool empty(){
        return s.empty();
    }
    int size(){
        return s.size();
    }
    int back(){
        return s.top();
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
    q.push(7);
    q.push(8);

    q.pop();

    cout << q.front() << endl;
    cout << q.back() << endl;

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    

    return 0;
}