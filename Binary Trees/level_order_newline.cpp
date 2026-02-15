#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = left;
        this->right = right;
    }    
};

void level_order(Node* root){
    if(root == NULL){
        cout << "Empty" << endl;
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* current = q.front();
        q.pop();

        if(current == NULL){
            cout << endl;
            if(q.empty()){
                break;
            }     
            q.push(NULL);    
        }   

        else{
            cout << current->data << " ";

        if(current->left != NULL)
            q.push(current->left);

        if(current->right != NULL)
            q.push(current->right);
        }
    }
}

int main(){
      
    Node* root = new Node(10);

    // Root Left
    Node* a = new Node(20);
    root->left = a;

    Node* b = new Node(40);
    a->left = b;
    a->right = NULL;

    b->left = NULL;
    b->right = NULL;

    //Root right
    Node* e = new Node(30);
    root->right = e;

    Node* f = new Node(50);
    e->left = f;    
    f->left = NULL;
    f->right = NULL;

    Node* g = new Node(60);
    e->right = g;
    g->left = NULL;
    g->right = NULL;    

    level_order(root);



    return 0;
}