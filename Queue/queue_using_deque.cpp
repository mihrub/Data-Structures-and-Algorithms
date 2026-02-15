#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<deque>
using namespace std;

class Queue{
    deque<int> deq;
public:
    void push(int val){
        deq.push_back(val);
    }    
    void pop(){
        deq.pop_front();
    }
    int front(){
        return deq.front();
    }
    int size(){
        return deq.size();
    }
    bool empty(){
        return deq.empty();
    }
};

int main(){
      
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "Front : " << q.front() << endl;
    cout << "Size : " << q.size() << endl;

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}