#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<stack>
using namespace std;

bool isValid(string str){

    stack<char> s;

    for(int i = 0; i<str.length(); i++){
        char ch = str[i];
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            s.push(str[i]);
        }
        else{
            if(s.empty()){
                return false;
            }
            char top = s.top();
            if((top == '(' && ch == ')') || (top == '{' && ch == '}') || (top == '[' && ch == ']')){
                s.pop();
            }
            else{
                return false;
            }
        }
    }
    return s.empty();
}

int main(){
      
    string s1 = "{({[()]})}";
    string s2 = "{()))))[(((]]]";

    isValid(s1)? cout << "YES" << endl : cout << "NO" << endl;
    isValid(s2)? cout << "YES" << endl : cout << "NO" << endl;
    
    return 0;
}