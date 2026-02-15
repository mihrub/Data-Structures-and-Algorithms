#include <iostream>
#include <vector>
using namespace std;

class Stack{
    vector<int> vec;
public:

    void push(int val){
        vec.push_back(val);
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

        cout << vec.back() << endl;

        //similar

        // int size = vec.size();
        // cout << vec.at(size-1) << endl;
        // cout << vec[size-1] << endl;

    }

    void print(){
        while(!isEmpty()){
            top();
            pop();
        }
    }

    bool isEmpty(){
        return vec.size() == 0;
    }
};

int main()
{
    Stack s;
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.print();
    s.pop();
    s.print();
    s.top();

    return 0;
}