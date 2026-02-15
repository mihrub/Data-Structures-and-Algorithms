#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

class Node{
public:
    int data;
    Node* next; // we use Node* because It points to a Node's Address.   
};

int main(){
    
    Node a,b,c;

    a.data = 20;
    b.data = 30;
    c.data = 40;

    a.next = &b;
    b.next = &c;
    c.next = NULL;

    //both same

    cout << a.data << " " << a.next->data <<  " " << a.next->next->data << endl;
    
    cout << a.data << " " << (*a.next).data << " " << (*(*a.next).next).data << endl;

    // At first we access next node address by using dot (.) operator then we de-reference it to get the node then from the node we access the data
    //using dot (.) operator. It will be same for multiple nodes just we have to repeat the process.

    return 0;
}