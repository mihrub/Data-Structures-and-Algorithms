/*
You have a singly linked list which is empty initially. Then you will be given Q queries. In each query you will be given two values X and V.

If X is 0 that means you will insert the value V to the head of the linked list.
If X is 1 then you will insert the value V to the tail of the linked list.
If X is 2 then you will delete the value Vth index of the linked list. Assume that index starts from 0. If the index is invalid, then you shouldn't perform the deletion.
After each query you need to print the linked list.

Sample Input 1

11
0 10
2 5
1 20
1 30
0 40
2 0
0 50
2 2
1 60
2 3
2 3

Sample Output 1

10 
10 
10 20 
10 20 30 
40 10 20 30 
10 20 30 
50 10 20 30 
50 10 30 
50 10 30 60 
50 10 30 
50 10 30

Sample Input 2

10
1 4
2 1
0 9
0 10
2 2
1 5
2 0
2 1
2 5
2 2

Sample Output 2

4 
4 
9 4 
10 9 4 
10 9 
10 9 5 
9 5 
9 
9 
9 

*/

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

void push_back(Node* &head,Node* &tail,int value){
    Node* newNode = new Node(value);
    if(head == NULL){
        head = tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

void push_front(Node* &head,Node* &tail,int value){
    Node* newNode = new Node(value);
    if(head == NULL){
        head = tail = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}

int count_element(Node* temp){

    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void delete_node(Node* &head,Node*& tail,int position){
    int index = count_element(head);
    
    if(index <= position){
        return;
    }
    else if(position == 0){
        Node* del = head;
        head = head->next;
        delete del;
    }
    else if(position == index-1){
        Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        tail = temp;
        tail->next = NULL;
    }
    else{
        Node* temp = head;

        for(int i = 0; i<position-1; i++){
            temp = temp->next;
        }
        Node* rmv = temp->next;
        temp->next = rmv->next;
        delete rmv;
    }
}

void print(Node* temp){
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main()
{
    int t;
    cin >> t;

    Node* head = NULL;
    Node* tail = NULL;

    while(t--){
        int x,y;
        cin >> x >> y;

        switch(x){
            case 0:
                push_front(head,tail,y);
                print(head);
                break;
            case 1:
                push_back(head,tail,y);
                print(head);
                break;
            case 2:
                delete_node(head,tail,y);
                print(head);
                break;           
        }
}
    return 0;
}
