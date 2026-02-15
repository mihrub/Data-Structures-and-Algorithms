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
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }
};

class List{
public:
    Node* head;
    Node* tail;
      
    List(){
        head = NULL;
        tail = NULL;
    }
    ~List(){
        if(head != NULL){
            delete head;
            head = NULL;
        }
    }

    void push_back(int val){
        Node * newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void push_front(int val){
        Node *newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void pop_front(){
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
        Node *temp = head;

        while(temp->next->next != NULL){ //  or temp->next != tail
            temp= temp->next;
        }

        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void print(){
        Node *temp = head;

        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverse(){
        Node* previous = NULL;
        Node* current = head;
        tail = head;
        while(current != NULL){
        Node* next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
    }
};  

int main(){

    List ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);

    ll.print();
    cout << "Head : " << ll.head->data << endl;
    cout << "Tail : " << ll.tail->data << endl;

    ll.reverse();
    ll.print();
    cout << "Head : " << ll.head->data << endl;
    cout << "Tail : " << ll.tail->data << endl;

    return 0;
}