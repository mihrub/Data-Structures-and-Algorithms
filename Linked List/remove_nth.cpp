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
private:
    Node* head;
    Node* tail;
    
public:    
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
    
    int get_size(){
        
        Node * temp = head;
        int count = 0;

        while(temp != NULL){
            temp = temp->next;
            count++;
        }

        return count;
    }

    void remove_Nth(int n){

        Node *prev = head;
        int size = get_size();

        for(int i = 0; i<(size-n) ; i++){
            prev = prev->next;
        }
        Node * todel = prev->next;
        cout << "Going to delete : " <<todel->data << endl;
        prev->next = prev->next->next;
        
    }
};


int main(){
      
    List ll;

    return 0;
}