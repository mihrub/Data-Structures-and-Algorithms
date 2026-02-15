/*
You will be given a singly linked list of integer values as input. You need to remove duplicate values from the linked list and finally print the linked list.

The process is, for each node N, traverse from that node and delete all nodes where the values are same with N.

Output Format
Output the final linked list where there will be no duplicate values.

Sample Input 2
5 5 1 1 2 4 2 4 1 3 5 0 -1

Sample Output 2
5 1 2 4 3 0
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

int count_element(Node* temp){

    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void sort_ll(Node* head){
    for(Node* i = head; i->next != NULL; i=i->next){
        for(Node* j = i->next; j != NULL; j=j->next){
            if(i->data > j->data){
                swap(i->data,j->data);
            }
        }
    }
}

void delete_ll(Node* &head){
    Node* temp = head;

    for(Node* i = temp; i != NULL; i = i->next){
        Node* a = i;
        Node* j = a->next;

        while(j != NULL){
            if(i->data == j->data){
                a->next = j->next;
                j = a->next;
            }
            else{
                a = j;
                j = j->next;
            }
        }
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
    int x;

    Node* head = NULL;
    Node* tail = NULL;

    while(true){
        cin >> x;
        if(x == -1){
            break;
        }
        push_back(head,tail,x);
    }

    delete_ll(head);
    print(head);



    return 0;
}
