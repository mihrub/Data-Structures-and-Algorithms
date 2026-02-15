#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<deque>
using namespace std;

class Stack{
    deque<int> deq;
public:
    void push(int val){
        deq.push_front(val);
    }    
    void pop(){
        deq.pop_front();
    }
    int top(){
        return deq.front();
    }
    bool empty(){
        return deq.empty();
    }
    int size(){
        return deq.size();
    }
};

int main(){

    Stack s;

    for(int i = 1; i<=10; i++){
        s.push(i);
    }

    cout << "Top : " << s.top() << endl;
    s.pop();
    cout << "Size : " << s.size() << endl;

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }    
    cout << endl;
    
    return 0;
}