#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<stack>
using namespace std;

string reverse_string(string str){
    string ans;
    stack<char> s;

    for(int i = 0; i<str.length(); i++){
        s.push(str[i]);
    }

    while(!(s.empty())){
        char ch = s.top();
        ans += ch;
        s.pop();
    }

    return ans;

} 

int main(){
      
   string str = "abcdef";
   cout << reverse_string(str) << endl;

    return 0;
    
}