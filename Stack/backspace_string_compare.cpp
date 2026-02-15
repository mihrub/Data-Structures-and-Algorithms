#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<stack>
using namespace std;

bool cmp(string s, string t){

    stack<char> ss;
    stack<char> tt;

    for(int i = 0; i<s.length(); i++){
        if(isalpha(s[i])){
            ss.push(s[i]);
        }
        else if(s[i] == '#'){
            if(!ss.empty()){
                ss.pop();
            }
        }
    }

    for(int i = 0; i<t.length(); i++){
        if(isalpha(t[i])){
            tt.push(t[i]);
        }
        else if(t[i] == '#'){
            if(!tt.empty()){
                tt.pop();
            }
        }
    }  
    
    return ss == tt;
}

int main(){
      
    string s;
    cin >> s;

    string t;
    cin >> t;

    cout << cmp(s,t) << endl;

    return 0;
}