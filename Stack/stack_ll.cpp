#include<iostream>
#include<vector>
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

class List{
public:
    Node* head;
    Node* tail;

    List(){
        head = NULL;
        tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);

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

    void print(){
        Node* temp = head;

        while (temp != NULL){
            cout << temp->data << " " << endl;
            temp = temp->next;
        }
    }

};

class Stack{
public:
    vector<int> vec;

    void push(int val){
        vec.push_back(val);
    }

    void pop(){
        if(isEmpty()){
            cout << "Stack is empty";
            return;
        }
        vec.pop_back();
    }

    bool isEmpty(){
        return vec.size() == 0;
    }

    void top(){
        cout << vec.back() << endl;
    }
};


int main(){

    List ll;
    ll.push_front(34);
    ll.push_front(56);

    ll.print();

    ll.pop_front();
    ll.print();




    return 0;
}