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

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_back(){
        Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void pop_front(){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void print(){
        Node* temp = head;
        cout << temp->data << " ";
        temp = temp->next;
        while(temp != head){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insert(int position, int value){
        Node* newNode = new Node(value);

        if(position == 0){
            newNode->next = head;
            head = newNode;
        }

        else{
        Node* temp = head;

        for(int i = 0; i<position-1 ; i++){
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        }
    }

    int get_count(){
        Node* temp = head;
        int count = 0;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }

    void erase(int position){

        Node* temp = head;

        for(int i = 0; i<position-1 ; i++){
            temp = temp->next;
        }

        temp->next = temp->next->next;
    }
};
    void menu(){
        cout << "1.Print List" << endl;
        cout << "2.Push Back -> LL" << endl;
        cout << "3.Pop Back -> LL" << endl;
        cout << "4.Insert -> LL" << endl;
        cout << "5.Erase -> LL" << endl;
        cout << "6.Push Front -> LL" << endl;
        cout << "7.Pop Front -> LL" << endl;
        cout << "8.Exit" << endl;
}

int main(){
      
    List ll;

    int n;
    cout << "Size of LL : " ;
    cin >> n;

    cout << "Data : " ;

    for(int i = 0 ; i<n ; i++){
        int a;
        cin >> a;
        ll.push_front(a);
    }

    while(true){
        int b;
        menu();
        cin >> b;
        if(b == 1){
            ll.print();
        }
        else if(b == 2){
            int c;
            cin >> c;
            ll.push_back(c);
        }
        else if(b == 3){
            ll.pop_back();
        }
        else if(b == 4){
            int position;
            cout << "Position : ";
            cin >> position;
            int value;
            cout << "Value : ";
            cin >> value;
            ll.insert(position,value);
        }
        else if(b == 5){
            int position;
            cout << "Position : ";
            cin >> position;
            ll.erase(position);            
        }
        else if(b == 6){
            int c;
            cin >> c;
            ll.push_front(c);
        }
        else if(b == 7){
            ll.pop_front();
        }
        else if( b == 8)
            break;

        getchar();
        system("cls");

    }

    return 0;
}