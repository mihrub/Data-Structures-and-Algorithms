#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<stack>
using namespace std;

void push_back(stack<int> &s, int value){

    if(s.empty()){
        s.push(value);
        return;
    }
    int temp = s.top();
    s.pop();
    push_back(s,value);
    s.push(temp);
}

void reverse_stack(stack<int> &s){

    if(s.empty()){
        return;
    }

    int temp = s.top();
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
    

    return 0;
}