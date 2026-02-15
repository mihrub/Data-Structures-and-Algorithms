#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }    
};

void preorder_traversal(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

int main(){

    Node* root = new Node(10);

    Node* a = new Node(20);
    root->left = a;

    Node* b = new Node(40);
    a->left = b;
    a->right = NULL;

    b->left = NULL;
    b->right = NULL;

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

    preorder_traversal(root);
    cout << endl;

    return 0;
}