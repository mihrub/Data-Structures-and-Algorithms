#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;

int priority (char a){
    if(a == '+' || a =='-')
        return 1;
 
    if(a == '*' || a =='/')
        return 2;
 
    if(a == '^')
        return 3;

    return 0;
}
string convert(string infix){
    int i = 0;
    string postfix = "";
    stack <char> s;

    while(infix[i] != '\0'){

        if(infix[i] >= 'a' && infix[i] <= 'z'|| infix[i] >= 'A' && infix[i] <= 'Z'){
            postfix += infix[i];
            i++;
        }

        else if(infix[i]=='('){
            s.push(infix[i]);
            i++;
        }

        else if(infix[i]==')'){

            while(s.top()!='('){
                postfix += s.top();
                s.pop();
            }

            s.pop();
            i++;
        }

        else{
            while(!s.empty() && priority(infix[i]) <= priority(s.top())){
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
            i++;
        }
    }
    
    while(!s.empty()){
        postfix += s.top();
        s.pop();
    }
    
    cout << "Postfix is : " << postfix;
    return postfix;
}

int main(){
    string infix;
    cin >> infix;

    string postfix;
    postfix = convert(infix);
    
    return 0;
}