
/*
            10      -> Root
           /   \
        20     30
       /  \    / \ 
     40   N  50   60
    / \     / \   / \
   N   N   N  N   N N     -> N = NULL = Leaf Node (End of Tree).

*/

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

void inorder_traversal(Node* root){
    if(root == NULL){
        return;
    }
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}

void postorder_traversal(Node* root){
    if(root == NULL){
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->data << " ";
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

    // Pre-Order traversal
    preorder_traversal(root);
    cout << endl;
    //In-Order traversal
    inorder_traversal(root);
    cout << endl;
    //Post-Order traveral
    postorder_traversal(root);
    

    return 0;
}