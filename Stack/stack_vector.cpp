#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

class Stack{
    vector<int> vec;
public:
    void push(int val){
        vec.push_back(val);
    }

    void pop(){
        if(!vec.empty()){
            vec.pop_back();
        }
        else{
            cout << "Stack is empty" << endl;
        }
    }

    void print(){
        while(!empty()){
            cout << top() << " ";
            pop();
        }
        cout << endl;
    }

    bool empty(){
        return vec.size() == 0;
    }

    int top(){
        int length = vec.size();
        if(length > 0){
            return vec.back();
        }
        return -1;
    }

    int size(){
        return vec.size();
    }
};

int main(){
      
    Stack s;

    s.push(1);
    s.push(2);
    s.push(4);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    s.push(22);
    s.push(44);   
    
    cout << s.size() << endl;
    cout << s.empty() << endl;
    s.print();
    s.pop();
    cout << s.empty() << endl;
    cout << s.size() << endl;
    cout << s.top() << endl;

    return 0;
}