#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }    
};

int main(){
      
    Node* head = new Node(12);  // head is present in stack memory which collects the address of a node and that node is created in the heap memory.
    Node* a = new Node(13);
    Node* b = new Node(14);

    head->next = a;

    // same
    a->next = b;
    head->next->next = b;

    cout << head->data << " " << head->next->data << " " << head->next->next->data << endl;
     

    return 0;
}