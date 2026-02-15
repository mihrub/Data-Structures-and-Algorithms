/*
Question: Take a stack of size N as input and copy those elements to another 
stack to get the values in the order they were inserted and print them. 
You should use STL to solve this problem.

Sample Input
5
10 20 30 40 50

Sample Output
10 20 30 40 50

*/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<stack>
using namespace std;
int main(){
      
    stack<int> s;
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        s.push(x);
    }

    stack<int> ss;

    while(!s.empty()){
        ss.push(s.top());
        s.pop();
    }

    while(!ss.empty()){
        cout << ss.top() << " ";
        ss.pop();
    }
    cout << endl;

    return 0;
}