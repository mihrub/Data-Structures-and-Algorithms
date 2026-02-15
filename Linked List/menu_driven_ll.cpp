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
    cout << "6.Inset a Value Before a Positon" << endl;
    cout << "7.Insert a Value After a Position" << endl;
    cout << "8.Delete a Value Before a Position" << endl;
    cout << "9.Delete a value After a Position" << endl;
    cout << "10.Count the Number of Elements" << endl;
    cout << "11.Search a Value" << endl;
    cout << "12.Check Empty" << endl;
    cout << "13.Reverse a Linked List" << endl;
    cout << "14.Front Element" << endl;
    cout << "15.Back Element" << endl;
    cout << "16.Sort List" << endl;
    cout << "17.Exit" << endl;
}

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this-> data = data;
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

    void pop_front(){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
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

    void print_ll(){
        Node* temp = head;
        cout << temp->data ;
        temp = temp->next;
        while(temp != NULL){
            cout <<" -> " << temp->data ;
            temp = temp->next;
        }
        cout << endl;
    }

    int number_of_elements(){
        Node* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;        
    }

    void count_element(){
        Node* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        cout << count << endl;
    }

    void search_ll(int key){
        Node* temp = head;
        bool flag = false;
        int count = 1;
        int counter = 0;

        while(temp != NULL){
            if(temp->data == key){
                cout << "Position : " << count << endl;
                flag = true;
                counter++;
            }
            temp = temp->next;
            count++;
        }
        if(flag){
            cout << key <<" Found "<< counter << " times in the Linked List" << endl;
        }
        else{
            cout << key << " Not Found in the Linked List" << endl;
        }
    }

    void check_empty(){
        if(head == NULL){
            cout << "Linked List is Empty" << endl;
        }
        else{
            cout << "Linked List is Not Empty" << endl;
            cout << "The number of elements : ";
            count_element();
        }
    }

    void insert_after_value(int position , int value){

        if((position-1) > number_of_elements()){
            cout << "Invalid Position" << endl;
            return;
        }

        if(position == 1){
            push_back(value);
            return;
        }

        Node* temp = head;
        int count = 0;

        while(count != position - 1){
            temp = temp->next;
            count++;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insert_before_value(int position , int value){

        if((position-1) > number_of_elements()){
            cout << "Invalid Position" << endl;
            return;
        }

        if(position == 1){
            push_front(value);
            return;
        }

        Node* temp = head;
        int count = 0;

        while(count != abs(position-2)){
            temp = temp->next;
            count++;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void delete_before_position(int position){

        if((position-1) > number_of_elements()){
            cout << "Invalid Position" << endl;
            return;
        }
        if(position == 1){
            pop_front();
            return;
        }

        Node* temp = head;
        int count = 0;

        while(count != abs(position-2)){
            temp = temp->next;
            count++;
        }
        temp->next = temp->next->next;
    }
    void delete_after_position(int position){

        if((position-1) > number_of_elements()){
            cout << "Invalid Position" << endl;
            return;
        }
        if(position == 1){
            pop_back();
            return;
        }

        Node* temp = head;
        int count = 0;

        while(count != position - 1){
            temp = temp->next;
            count++;
        }
        temp->next = temp->next->next;
    }    

    void reverse_ll(){
        Node* current = head;
        Node* previous = NULL;
        tail = head;
        
        while(current != NULL){
            Node* next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
    }
    int front(){
        return head->data;
    }
    int back(){
        return tail->data;
    }

    void sort(){
        for(Node* i = head; i != NULL; i = i->next){
            for(Node* j = i->next; j != NULL; j = j->next){
                if(i->data > j->data){
                    swap(i->data,j->data);
                }
            }
        }
    }    
};

int main(){

    List ll;

    while(true){
    int number;    
    display(); 
    cout << endl << endl;   
    cout << "Enter Number between(1-14) : ";
    cin >> number;

    switch(number){
        case 1:{
            int value;
            cout << "Enter a Value : ";
            cin >> value;
            ll.push_front(value);
            break;
        }
        case 2:{
            int value;
            cout << "Enter a Value : ";
            cin >> value;
            ll.push_back(value);
            break;            
        }
        case 3:{
            ll.pop_front();
            cout << "Front Element Popped" << endl;
            break;            
        }
        case 4:{
            ll.pop_back();
            cout << "Back Element Popped" << endl;
            break;
        }
        case 5:{
            cout << "Printing List : " ;
            ll.print_ll();
            break;
        }
        case 6:{
            int value;
            cout << "Value : ";
            cin >> value;

            int position;
            cout << "Position : ";
            cin >> position;
            ll.insert_before_value(position,value);
            break;
        }
        case 7:{
            int value;
            cout << "Value : ";
            cin >> value;

            int position;
            cout << "Position : ";
            cin >> position;
            ll.insert_after_value(position,value);
            break;            
        }
        case 8:{
            int position;
            cout << "Position : ";
            cin >> position;
            ll.delete_before_position(position);
            break;
        }
        case 9 :{
            int position;
            cout << "Position : ";
            cin >> position;
            ll.delete_after_position(position);
            break;            
        }
        case 10:{
            cout << "Number of elements : ";
            ll.count_element();
            break;
        }
        case 11:{
            int key;
            cout << "Key : ";
            cin >> key;
            ll.search_ll(key);
            break;
        }
        case 12:{
            ll.check_empty();
            break;
        }
        case 13:{
            cout << "Reversing....." << endl;
            ll.reverse_ll();
            break;
        }
        case 14:{
            cout << "Front : " << ll.front() << endl;
            break;
        }
        case 15:{
            cout << "Back : " << ll.back() << endl;
            break;
        }
        case 16:{
            cout << "Sorted List : "; 
            ll.sort();
            break;
        }
        case 17:{
            cout << endl << "**********......Exiting Program......**********" << endl;
            exit(0);
        }

        default:
            cout << "Number is not in the Range !! Please Enter Carefully !!" << endl;
    }
}
    return 0;
}