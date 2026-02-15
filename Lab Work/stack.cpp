#include <iostream>
#include <vector>
using namespace std;

class Stack{
    vector<int> vec;
public:

    void push(int val){
        vec.push_back(val);
    }

    bool isEmpty(){
        return vec.size() == 0;
    }

    void pop(){

        if(isEmpty()){
            cout << "Stack is Empty" << endl;
            return;
        }

        vec.pop_back();
    }

    void top(){

        if(isEmpty()){
            cout << "Stack is Empty" << endl;
            return;
        }

        cout << vec.back() << " ";

    }

    void print(){
        while(!isEmpty()){
            top();
            pop();
        }
    }

};

int main()
{
    Stack s;
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);

    s.pop();
    s.top();

    cout << endl;
    
    s.print();

    return 0;
}