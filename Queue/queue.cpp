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

class Queue{
    Node* head;
    Node* tail;
public:
    Queue(){
        head = NULL;
        tail = NULL;
    }

    void push(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    void pop(){
        if(empty()){
            cout << "Queue is Empty" << endl;
            return;
        }
            Node* temp = head;
            head = head->next;
            delete temp;
            temp = NULL;
    }

    int front(){
        return head->data;
    }

    bool empty(){
        return head == NULL;
    }
};

int main(){
      
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}