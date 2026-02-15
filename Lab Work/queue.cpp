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
        this->next = NULL;
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

    void push_back(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_back(){
        if(head == NULL){
            cout << "Queue is Empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        temp = NULL;
    }

    void print(){
        Node* temp = head;
        if(temp == NULL){
            cout << "Queue is Empty" << endl;
            return;
        }
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void display(){
    cout << "*************Queue*************" << endl;
    cout << "1.Push" << endl;
    cout << "2.Pop" << endl;
    cout << "3.Print" << endl;
    cout << "4.Exit" << endl;
}

int main(){

    Queue q;
      
    while(true){
        display();
        int a;
        cout << "Enter between 1 to 4 : ";
        cin >> a;
        switch(a){
            case 1:{
                int x;
                cout << "Enter size of Queue : ";
                cin >> x;
                for(int i = 0; i<x; i++){
                    int b;
                    cin >> b;
                    q.push_back(b);
                }
                break;
            }
            case 2:{
                q.pop_back();
                break;
            }
            case 3:{
                q.print();
                break;
            }
            case 4:
                exit(0);
            default:
                cout << "Invalid" << endl;

        }
    }
    

    return 0;
}