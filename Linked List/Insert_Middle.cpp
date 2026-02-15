#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    
    Node(int value){
        data = value;
        next = NULL;
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

void insert(int val, int pos){
    Node *newNode = new Node(val);
    Node *temp = head;

    for(int i = 0; i<pos-1; i++){
        if(temp == NULL){
            cout << "Invaild Index" << endl;
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

} 

};

int main(){

    List ll;
    
    return 0;
}