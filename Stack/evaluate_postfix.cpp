#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<stack>
using namespace std;

int evaluate(int a,int b, char c){
    if(c == '+')
        return b+a;
    else if(c == '-')
        return b-a;
    else if(c == '*')
        return b*a;
    else if(c == '/')
        return b/a;
    else if(c == '^')
        return pow(b,a);    
    else    
        return 0;                
}

void evaluate_postfix(string postfix){
    stack<int> s;
    for(int i = 0; i<postfix.length(); i++){
        char ch = postfix[i];
        if(isdigit(ch)){
            s.push(ch - '0');
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            int result = evaluate(a,b,ch);
            s.push(result);
        }
    }
    cout << s.top() << endl;
}

int main(){
      
    string postfix;
    cin >> postfix;

    evaluate_postfix(postfix);

    return 0;
}