#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

void display(){
    cout << endl << "*************** Main Menu ***************" << endl;
    cout << "1.Traverse - Forward" << endl;
    cout << "2.Traverse - Backward" << endl;
    cout << "3.Searching" << endl;
    cout << "4.Push Front" << endl;
    cout << "5.Push Back" << endl;
    cout << "6.Insert Any Position" << endl;
    cout << "7.Check Empty" << endl;
    cout << "8.Pop Front" << endl;
    cout << "9.Pop Back" << endl;
    cout << "10.Delete Specific Value" << endl;
    cout << "11.Delete Specific Position" << endl;
    cout << "12.Reverse Doubly List" << endl;
    cout << "13.Size of Doubly List" << endl;
    cout << "14.Sort in ascending order" << endl;
    cout << "15.Sort in decending order" << endl;
    cout << "16.Clear Doubly List" << endl;
    cout << "17.Front Element" << endl;
    cout << "18.Back Element" << endl;
    cout << "19.Exit" << endl;

    cout << endl;
}

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

class DoublyList{
public:

    Node* head;
    Node* tail;

    DoublyList(){
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
            newNode->previous = tail;
            tail = newNode;
        }
    }

    void push_front(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
    }

    void pop_back(){
        Node* temp = tail;
        tail = tail->previous;
        tail->next = NULL;
        delete temp;
        temp = NULL;
    }

    void pop_front(){
        Node* temp = head;
        head = head->next;
        head->previous = NULL;
        delete temp;
        temp = NULL;
    }

    void search(int value){
        Node* temp = head;
        int count = 0;
        int idx = 0;
        bool flag = false;
        vector<int> v;

        while(temp != NULL){
            if(temp->data == value){
                flag = true;
                v.push_back(idx);
                count++;                
            }
            idx++;
            temp = temp->next;
        }
        if(flag){
            cout << "Found" << endl;
            cout << "At Index : " ;
            for(int x : v){
                cout << x << " ";
            }
            cout << endl;
            cout << "Frequency : " << count << endl;
        }
        else{
            cout << "Not Found" << endl;
        }
    }

    void insert(int position, int value){

        if(position == 0){
            push_front(value);
        }

        else if(position == size() - 1){
            push_back(value);
        }

        else if(position > size()){
            cout << "Invaild Operation" << endl;
            forward_traverse();
            return;
        }

        else{
        Node* temp = head;
        Node* newNode = new Node(value);
        for(int i = 0; i<position; i++){
            temp = temp->next;
        }
        newNode->next = temp;
        newNode->previous = temp->previous;
        temp->previous->next = newNode;
        temp->previous = newNode;
        }        
    }

    void erase(int position){

        if(position == 0){
            pop_front();
        }

        else if(position == size() - 1){
            pop_back();
        }

        else if(position > size()){
            cout << "Invaild Operation" << endl;
            forward_traverse();
            return;
        }

        else{
        Node* temp = head;
        for(int i = 0; i<position; i++){
            temp = temp->next;
        }
        temp->previous->next = temp->next;
        temp->next->previous = temp->previous;
        }
    }

    void remove(int value){
        Node* temp = head;
        while(temp != NULL){
            if(temp->data == value){
        temp->previous->next = temp->next;
        temp->next->previous = temp->previous;                
            }
            temp = temp->next;
        }
    }

    void clear(){
        Node* temp = head;
        while(temp != NULL){
            Node* del = temp;
            temp = temp->next;
            delete del;
            del = NULL;
        }
        head = NULL;
        tail = NULL;
    }

    int size(){
        Node* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        } 
        return count;
    }

    void sort_ascending(){
        for(Node* i = head; i != NULL; i = i->next){
            for(Node* j = i->next; j != NULL; j = j->next){
            if(i->data > j->data)
                swap(i->data,j->data);
            }
        }
    }

    void sort_decending(){
        for(Node* i = head; i != NULL; i=i->next){
            for(Node* j = i->next; j != NULL ; j = j->next){
                if(i->data < j->data){
                    swap(i->data,j->data);
                }
            }
        }
    }

    void reverse(){
        Node* i = head;
        Node* j = tail;
        while(i != j && i->previous != j){
            swap(i->data,j->data);
            i = i->next;
            j = j->previous;
        }
    }

    void forward_traverse(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverse_traverse(){
        Node* temp = tail;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->previous;
        }
        cout << endl;
    }

    int front(){
        return head->data;
    }

    int back(){
        return tail->data;
    }

    void insert_before_value(int positon,int value){
        Node* temp = head;
        Node* newNode = new Node(value);
        for(int i = 0; i<positon-1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->previous = temp;
        temp->next->previous = newNode;
        temp->next = newNode;
    }

    bool empty(){
        return head == NULL;
    }    

};

int main(){
    
    DoublyList dbl;

    while(true){
    int number;    
    display(); 
    cout << endl << endl;   
    cout << "Enter Number between(1-14) : ";
    cin >> number;

    switch(number){
        case 1:{
            cout << "Forward Traverse : ";
            dbl.forward_traverse();
            break;
        }
        case 2:{
            cout << "Reverse Traverse : ";
            dbl.reverse_traverse();
            break;            
        }
        case 3:{
            int value;
            cout << "Value : ";
            cin >> value;
            dbl.search(value);
            break;            
        }
        case 4:{
            int value;
            cout << "Value : ";
            cin >> value;
            dbl.push_back(value);
            cout << "Front Element Pushed" << endl;
            break;
        }
        case 5:{
            int value;
            cout << "Value : ";
            cin >> value;
            dbl.push_back(value);
            cout << "Back Element Pushed" << endl;
            break;
        }
        case 6:{
            int value;
            cout << "Value : ";
            cin >> value;

            int position;
            cout << "Position : ";
            cin >> position;
            dbl.insert(position,value);
            break;
        }
        case 7:{
            (dbl.empty())? cout << "Empty" << endl : cout << "Not Empty" << endl;
            break;            
        }
        case 8 :{
            dbl.pop_front();
            cout << "Front Element Popped" << endl;
            break;            
        }
        case 9:{
            dbl.pop_back();
            cout << "Back Element Popped" << endl;
            break;
        }
        case 10:{
            int value;
            cout << "Value : ";
            cin >> value;
            dbl.remove(value);
            break;
        }
        case 11:{
            int position;
            cout << "Position : ";
            cin >> position;
            dbl.erase(position);
            break;
        }
        case 12:{
            cout << "Reversing....." << endl;
            dbl.reverse();
            break;
        }
        case 13:{
            cout << "Size : " << dbl.size() << endl;
            break;
        }    
        case 14:{
            cout << "Sorted in Ascending Order : ";
            dbl.sort_ascending();
            break;
        }    
        case 15:{
            cout << "Sorted in Decending Order : ";
            dbl.sort_decending();
            break;
        }    
        case 16:{
            cout << "List Becomes Empty" << endl;
            dbl.clear();
            break;  
        }  
        case 17:{
            cout << "Front : " << dbl.front() << endl;
            break;
        }   
        case 18:{
            cout << "Back : " << dbl.back() << endl;
            break;            
        }             
        case 19:{
            cout << endl << "**********......Exiting Program......**********" << endl;
            exit(0);
        }
        default:
            cout << "Number is not in the Range !! Please Enter Carefully !!" << endl;
    }
}
    return 0;
}