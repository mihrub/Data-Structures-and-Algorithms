#include<iostream>
#include<list>
#include<iterator>
using namespace std;

void print(list<int> ll){

    for( list<int> :: iterator itr = ll.begin(); itr != ll.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl;
}

int main(){
    
    list<int> ll;

    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    
    ll.push_back(5);
    ll.push_back(6);

    print(ll);

    cout << *(ll.begin()) << endl;
    cout << *(ll.end()) << endl;

    //similar function

    cout << ll.front() << endl;
    cout << ll.back() << endl;

    // size

    cout << ll.size() << endl;

    //pop elements
    
    ll.pop_back();
    ll.pop_front();

    print(ll);

    return 0;
}