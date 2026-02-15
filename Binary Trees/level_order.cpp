
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
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }    
};

void level_order_traversal(Node* root){

    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* currentNode = q.front();
        q.pop();
        cout << currentNode->data << " ";
        if(currentNode->left != NULL){
            q.push(currentNode->left);
        }
        if(currentNode->right != NULL){
            q.push(currentNode->right);
        }
    }
    cout << endl;
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

    level_order_traversal(root);
    

    return 0;
}