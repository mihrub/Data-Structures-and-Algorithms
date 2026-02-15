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
    Node* previous;
    Node(int data){
        this->data = data;
        next = NULL;
        previous = NULL;
    }
};

class Stack{
    Node* head;
    Node* tail;
    int length;
public:

    Stack(){
        head = NULL;
        tail = NULL;
        length = 0;
    }

    void push(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
        length++;
    }
    
    void pop(){

        if(empty()){
            return;
        }

        Node* del = tail;
        tail = tail->previous;

        if(tail != NULL){
            tail->next = NULL; 
        } 

        else{
            head = NULL;
        }      
            
        delete del;
        length--;
    }

    int top(){
        if(!empty())
            return tail->data;
        else    
            return -1;    
    }

    bool empty(){
        return head == NULL;
    }

    int size(){
        return length;
    }

    void print(){
        while(!empty()){
            cout << top() << " ";
            pop();
        }
        cout << endl;
    }
};

int main(){
      
    Stack s;

    s.push(1);
    s.push(2);
    s.push(4);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    s.push(22);
    s.push(44);   
    
    cout << s.size() << endl;
    cout << s.empty() << endl;
    s.print();
    s.pop();
    cout << s.empty() << endl;
    cout << s.size() << endl;
    cout << s.top() << endl;


    return 0;
}