#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
    ~Node(){
        if (next != NULL){
            delete next;
            next = NULL;
        }
    }
};

class List{
public:
    Node *head;
    Node *tail;

    List(){
        head = NULL;
        tail = NULL;
    }
    ~List(){
        if (head != NULL){
            delete head;
            head = NULL;
        }
    }

    void push_front(int val){
        Node *newNode = new Node(val);
        if (head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node *newNode = new Node(val);
        if (head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front(){
        if (head == NULL){
            return;
        }
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
        if (head == NULL){
            return;
        }
        Node *temp = head;
        while (temp->next->next != NULL){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void print(){
        Node *temp = head;
        while (temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){

    List ll;

    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.push_back(5);
    ll.push_back(6);

    ll.pop_back();
    ll.pop_front();

    ll.print();

    return 0;
}
