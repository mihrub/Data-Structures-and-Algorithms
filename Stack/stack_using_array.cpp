#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

#define SIZE 10

class Stack{
    int arr[SIZE];
    int count = -1;
public:
    void push(int val){
        if(count == SIZE -1){
            cout << "Overflow" << endl;
            return;
        }
        arr[++count] = val;
    }
    void pop(){
        if(count == -1){
            cout << "Underflow" << endl;
            return;
        }
        count--;
    }
    int top(){
        if(!empty())
            return arr[count];
        else  
            return -1;    
    }
    bool empty(){
        return count == -1;
    }
    void print(){
        while(count != -1){
            cout << arr[count--] << " ";
        }
        cout << endl;
    }
};

int main(){
    
    Stack s;

    while(true){
        int x;
        cin >> x;
        if(x == -1){
            break;
        }
        s.push(x);
    }

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    s.print();
    cout << s.empty() << endl;
    s.pop();
    

    return 0;
}