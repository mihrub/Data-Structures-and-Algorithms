#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
using namespace std;

void first_non_repeating_char(string s){
    queue<char> q;
    int freq[27] = {0};
    int length = s.length();
    for(int i = 0; i<length; i++){
        q.push(s[i]);
        freq[s[i]-'a']++;
        while(!q.empty() && freq[q.front()-'a'] > 1){
            q.pop();
        }  
        if(q.empty()){
            cout << "-1";
        }
        else{
            cout << q.front();
        }
    }
}

int main(){
      
    string s;
    cin >> s;
    first_non_repeating_char(s);

    return 0;
}