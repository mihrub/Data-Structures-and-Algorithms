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

Node* inputTree(){
    int x;
    cin >> x;
    Node* root;
    if(x == -1){
        return NULL;
    }
    else{
        root = new Node(x);
    }
    queue<Node*>q;
    if(root != NULL){
        q.push(root);
    }
    while(!q.empty()){

        Node* front = q.front();
        q.pop();
        Node* myLeft,*myRight;
        int a,b;
        cin >> a >> b;        
        if(a == -1){
            myLeft = NULL;
        }
        else{
            myLeft = new Node(a);
        }
        if(b == -1){
            myRight = NULL;
        }
        else{
            myRight = new Node(b);
        }
        front->left = myLeft;
        front->right = myRight;
        if(front->left != NULL){
            q.push(front->left);
        }
        if(front->right != NULL){
            q.push(front->right);
        }
    }
    return root;
}

void postorder_traversal(Node* root){
    if(root == NULL){
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->data << " ";
}

void print_leaf_nodes(Node* root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        cout << root->data << " ";
        return;
    }
    print_leaf_nodes(root->left);
    print_leaf_nodes(root->right);
}

int main(){
      
    Node* root = inputTree();
    print_leaf_nodes(root);
    

    return 0;
}