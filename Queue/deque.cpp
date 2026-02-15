#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<deque>
using namespace std;
int main(){
      
    deque<int> deq;

    deq.push_front(1);
    deq.push_front(2);

    deq.push_back(3);
    deq.push_back(4);

    for(int x: deq){
        cout << x << " ";
    }
    cout << endl;

    cout << "Front : "  << deq.front() << endl;
    cout << "Back : " << deq.back() << endl;

    deq.pop_back();
    deq.pop_front();

    cout << "Front : " << deq.front() << endl;
    cout << "Back : " << deq.back() << endl;

    for(int x: deq){
        cout << x << " ";
    }
    cout << endl;   

    return 0;
}