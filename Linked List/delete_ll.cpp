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
    
    Node(int val){
    data = val;
    next = NULL;
    }

    ~Node(){
        cout << "~Node " << data << endl; 
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }
};

class List{
private:
    Node* head;
    Node* tail;
    
public:
    List(){
    head = NULL;
    tail = NULL;
    }   
    
    ~List(){
        cout << "~List " << endl;
        if(head != NULL){
            delete head;
            head = NULL;
        }
    }
    
    void push_front(int val){
        Node* newNode = new Node (val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node *newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print(){
        Node *temp = head;

        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
      
    List ll;
    ll.push_front(1);
    ll.push_back(2);
    ll.push_front(0);
    ll.push_back(3);

    ll.print();
    

    return 0;
}