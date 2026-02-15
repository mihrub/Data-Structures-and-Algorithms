/*
You are given a doubly linked list of unique string values. These strings refer to web addresses without any spaces. You will be given Q queries. In each query you will be given some commands. 
Type of commands are -

visit address - You need to go to that address from where you are in that list and print that address if it is in the list. Otherwise print "Not Available".
next - You need to go to the next address from where you are in that list and print that address if it is in the list. Otherwise print "Not Available".
prev - You need to go to the previous address from where you are in that list and print that address if it is in the list. Otherwise print "Not Available".
One more thing, if the address isn't available make sure you don't move from your current position. You are at the head initially.

Note: You can use Singly/Doubly Linked List or STL List to solve this problem.

Input Format

First line will contain the values of the doubly linked list, and will terminate with the string "end".
Second line will contain Q.
Next Q lines will contain the commands. It is guranteed that you will get "visit address" command at first which will contain a valid address. It will not contain valid address everytime!

--Sample Input 0

facebook google phitron youtube twitter end
12
visit phitron
prev
prev
prev
prev
next
visit twitter
next
next
prev
visit django
prev

--Sample Output 0

phitron
google
facebook
Not Available
Not Available
google
twitter
Not Available
Not Available
youtube
Not Available
phitron

--Sample Input 1

a b c d e f g h i j k l m n o p q r s t u v w x y z end
7
visit s
next
visit zz
next
visit z
next
prev

--Sample Output 1

s
t
Not Available
u
z
Not Available
y
*/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

class Node{
public:
    string data;
    Node* next;
    Node* previous;
    Node(string data){
        this->data = data;
        next = NULL;
        previous = NULL;
    }
};

void push_back(Node* &head, Node* &tail,string val){
    Node* newNode = new Node(val);

    if(head == NULL){
        head = tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
}

int main(){
      
    Node* head = NULL;
    Node* tail = NULL;

    while(true){
        string ss;
        cin >> ss;
        if(ss == "end"){
            break;
        }
        push_back(head,tail,ss);
    }

    int t;
    cin >> t;
    cin.ignore();

    Node* temp = head;

    while(t--){
        string s;
        getline(cin,s);

        stringstream ss(s);
        string word;
        ss >> word;

        if(word == "visit"){
            Node* temp2 = head;
            ss >> word;
            bool flag = false;
            while(temp2 != NULL){
                if(temp2->data == word){
                    cout << word << endl;
                    flag = true;
                    temp = temp2;
                    break;
                }
                temp2 = temp2->next;
            }
            if(!flag){
                cout << "Not Available" << endl;
            }
        }
        else if(word == "next"){
            if(temp->next == NULL){
                cout << "Not Available" << endl;
            }
            else{
                temp = temp->next;
                cout << temp->data << endl;
            }
        }
        else{
            if(temp->previous == NULL){
                cout << "Not Available" << endl;                
            }
            else{
                temp = temp->previous;
                cout << temp->data << endl;
            }
        }
    }
    
    return 0;
}