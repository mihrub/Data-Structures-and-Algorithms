/*
Take two stacks of size N and M as input and check 
if both of them are the same or not.
Don’t use STL stack to solve this problem.

Sample Input
5
10 20 30 40 50
5
10 20 30 40 50

Sample Output
YES

Sample Input
5
10 20 30 40 50
4
10 20 30 40

Sample Output
NO

Sample Input
5
10 20 30 40 50
5
50 40 30 20 10

Sample Output
NO

*/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

class Stack{
    vector<int> vec;
public:
    void push(int val){
        vec.push_back(val);
    }   
    void pop(){
        vec.pop_back();
    } 
    int top(){
        return vec.back();
    }
    bool empty(){
        return vec.size() == 0;
    }
    int size(){
        return vec.size();
    }
};

void check(Stack s, Stack ss){
    int length1 = s.size();
    int length2 = ss.size();

    if(length1 != length2){
        cout << "NO" << endl;
    }
    else{
        while(!s.empty()){
            if(s.top() != ss.top()){
                cout << "NO" << endl;
                return;
            }
            s.pop();
            ss.pop();
        }
        cout << "YES" << endl;
    }
}

int main(){
    
    Stack s;
    int n;
    cin >> n;

    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        s.push(x);
    }

    Stack ss;

    int m;
    cin >> m;

    for(int i = 0; i<m; i++){
        int x;
        cin >> x;
        ss.push(x);
    }

    check(s,ss);
    

    return 0;
}