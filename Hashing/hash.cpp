#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

class Node{
public:
    string key;
    int data;
    Node* next;
    Node(string key,int data){
        this->data = data;
        this->key = key;
        next = NULL;
    }    
    ~Node(){
        if(next != NULL){
            delete next;
        }
    }
};

class HashTable{
    int total_size;
    int current_size;
    Node** table;

    int hash_function(string key){
        int index = 0;
        for(int i = 0; i<key.length(); i++){
            int letter = key[i];
            index = index + ((letter * letter) % total_size);
        }
        return index % total_size;
    }

    void rehash(){
        Node** oldTable = table;
        int oldSize = total_size;
        total_size = 2*total_size;
        current_size = 0;
        table = new Node*[total_size];

        for(int i = 0; i<total_size; i++){
            table[i] = NULL;
        }

        for(int i = 0; i<oldSize; i++){
            Node* temp = oldTable[i];
            while(temp != NULL){
                insert(temp->key,temp->data);
                temp = temp->next;
            }
            if(oldTable[i] != NULL){
                delete oldTable[i];
            }
        }
        delete[] oldTable;
    }

public:
    HashTable(int total_size){
        this->total_size = total_size;
        current_size = 0;
        table = new Node*[total_size];
        for(int i = 0; i<total_size; i++){
            table[i] = NULL;
        }
    }    
    void insert(string key,int data){
        int index = hash_function(key);
        Node* newNode = new Node(key,data);

        newNode->next = table[index];
        table[index] = newNode;
        current_size++;

        double lamda = current_size/(double)total_size;

        if(lamda > 1){
            rehash();
        }
    }

    bool exists(string key){
        int index = hash_function(key);
        Node* temp = table[index];
        while(temp != NULL){
            if(temp->key == key){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int search(string key){
        int index = hash_function(key);
        Node* temp = table[index];
        while(temp != NULL){
            if(temp->key == key){
                return temp->data;
            }
            temp = temp->next;
        }
        return -1;
    }

    void remove(string key){
       int index = hash_function(key);
       Node* temp = table[index];
       Node* prev = temp;
       while(temp != NULL){
        if(temp->key == key){
            if(prev == temp){
                table[index] = temp->next;
            }
            else{
                prev->next = temp->next;
            }
            break;
        }
            prev = temp;
            temp = temp->next;
       }
    }

    void print(){
        for(int i = 0; i<total_size; i++){
            Node* temp = table[i];
            cout << "Index : " << i << endl;
            while(temp != NULL){
                cout << " (" << temp->data << "," << temp->key << ") ";
                temp = temp->next;
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main(){
      
    HashTable ht(5);

    ht.insert("USA",4000);
    ht.insert("UK",2500);
    ht.insert("Australia",3000);
    ht.insert("Canada",3500);
    ht.insert("Egypt",2000);
    ht.insert("China",1000);
    ht.insert("England",2222);

    ht.print();

    cout << "-----------" << endl;

    ht.remove("China");

    ht.print();    

    cout << "Canada : " << ht.search("Canada") << endl;

    if(ht.exists("Bangladesh")){
        cout << "Bangladesh Found" << endl;
    }
    else{
        cout << "Bangladesh Not Found" << endl;
    }

    return 0;
}