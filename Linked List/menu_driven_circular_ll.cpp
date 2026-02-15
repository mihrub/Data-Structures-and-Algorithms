#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

void display(){
    cout << endl << "*************** Main Menu ***************" << endl;
    cout << "1.Push From Front" << endl;
    cout << "2.Push From Back" << endl;
    cout << "3.Pop From Front" << endl;
    cout << "4.Pop From Back" << endl;
    cout << "5.Print Linked List" << endl;
    cout << "6.Count the Number of Elements" << endl;
    cout << "7.Search a Value" << endl;
    cout << "8.Check Empty" << endl;
    cout << "9.Front Element" << endl;
    cout << "10.Back Element" << endl;
    cout << "11.Exit" << endl;
}

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class CircularList{
    Node* head;
    Node* tail;
public:
    CircularList(){
        head = NULL;
        tail = NULL;
    }
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            tail->next = head;
        }
        else{
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
    }    
    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            tail->next = head;
        }
        else{
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
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
    void pop_back(){
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        delete tail;
        temp->next = head;
        tail = temp;
    }
    void pop_front(){
        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }
    bool Cycle(){
        Node* slow = head;
        Node* fast = head;
        while(fast != NULL && fast->next != NULL){
            if(fast == slow){
                return true;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return false;
    }
    void search(int val){
        Node* temp = head;
        if(temp->data = val){
            cout << "Found" << endl;
            return;
        }
        temp = temp->next;
        while(temp != head){
            if(temp->data == val){
                cout << "Found" << endl;
                return;
            }
        }
        cout << "Not Found" << endl;
    }
    int front(){
        return head->data;
    }
    int back(){
        return tail->data;
    }

    int size(){
        int count = 0;
        Node* temp = head;
        if(temp == NULL){
            return 0;
        }
        else{
            temp = temp->next;
            count++;
        }
        while(temp != head){
            temp = temp->next;
            count++;
        }
        return count;
    }

    bool empty(){
        return head == NULL;
    }
    
};

int main(){
      
    CircularList c;

    while(true){
        int x;
        cin >> x;
        if(x == -1){
            break;
        }
        c.push_back(x);
    }

    cout << c.front() << endl;
    cout << c.back() << endl;

    c.print();

    c.pop_back();

    c.print();

    cout << c.Cycle() << endl;

    c.pop_front();

    c.print();

    cout << c.Cycle() << endl;
    
    cout << c.front() << endl;
    cout << c.back() << endl;


    return 0;
}