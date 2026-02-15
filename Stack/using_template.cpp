#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<stack>
using namespace std;

template<typename T>

void push_back(stack<T> &s, T value){

    if(s.empty()){
        s.push(value);
        return;
    }
    T temp = s.top();
    s.pop();
    push_back(s,value);
    s.push(temp);
}

template<typename T>

void reverse_stack(stack<T> &s){

    if(s.empty()){
        return;
    }

    T temp = s.top();
    s.pop();
    reverse_stack(s);
    push_back(s,temp);

}

int main(){
      
    stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    reverse_stack(s);
    cout << "Reversed : " << endl;

    while(!(s.empty())){
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;

    stack<char> ch;

    ch.push('a');
    ch.push('b');
    ch.push('c');

    reverse_stack(ch);
    cout << "Reversed : " << endl;
    
    while(!(ch.empty())){
        cout << ch.top() << " ";
        ch.pop();
    }

    cout << endl;


    return 0;
}