#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<stack>
using namespace std;

int precedence(char c){
    if(c == '+' || c == '-')
        return 1;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '^')
        return 3;
    else    
        return -1;            
}
string infix_to_postfix(string infix){
    string postfix = {};
    stack<char> s;
    for(int i = 0; i<infix.length(); i++){
        if(isalpha(infix[i])){
            postfix += infix[i];
        }
        else if(infix[i] == '('){
            s.push(infix[i]);
        }
        else if(infix[i] == ')'){
            while(s.top() != '('){
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else{ 
            while (!s.empty() && s.top() != '(' && (precedence(infix[i]) < precedence(s.top()) || (precedence(infix[i]) == precedence(s.top()) && infix[i] != '^'))){
                postfix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
    }
    while(!s.empty()){
        postfix += s.top();
        s.pop();
    }
    return postfix;
}


string infix_to_prefix(string infix){

    reverse(infix.begin(),infix.end());

    for(int i = 0; i<infix.length(); i++){
        if(infix[i] == '('){
            infix[i] =')';
        }
        else if(infix[i] == ')'){
            infix[i] = '(';
        }
    }

    string prefix = {};
    stack<char> s;

    for(int i = 0; i<infix.length(); i++){
        if(isalpha(infix[i])){
            prefix += infix[i];
        }
        else if(infix[i] == '('){
            s.push(infix[i]);
        }
        else if(infix[i] == ')'){
            while(s.top() != '('){
                prefix += s.top();
                s.pop();
            }
            s.pop();
        }
        else {
            while (!s.empty() && s.top() != '(' && (precedence(infix[i]) < precedence(s.top()) || (precedence(infix[i]) == precedence(s.top()) && infix[i] == '^'))) {
                prefix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
    }

    while(!s.empty()){
        prefix += s.top();
        s.pop();
    }
    reverse(prefix.begin(),prefix.end());

    return prefix;    
}

int main(){
      
    string infix;
    cout << "Infix : ";
    cin >> infix;

    string postfix = infix_to_postfix(infix);
    cout << "Postfix : " << postfix << endl;

    string prefix = infix_to_prefix(infix);
    cout << "Prefix : " << prefix << endl;


    return 0;
}