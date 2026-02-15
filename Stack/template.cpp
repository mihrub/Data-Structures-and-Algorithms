#include <iostream>
#include <vector>
using namespace std;


template<class T>

class Stack{
    vector<T> vec;
public:

    void push(T val){
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
    Stack<int> s;
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.print();
    s.pop();
    s.print();
    s.top();

    Stack<char> s1;
    s1.push('a');
    s1.push('b');
    s1.push('c');
    s1.push('d');
    s1.top();       
    s1.print();
    s1.top();

    return 0;
}