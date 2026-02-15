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
    int a;
    cin >> a;
    if(a == -1){
        return NULL;
    }
    Node* root = new Node(a);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){

        Node* front = q.front();
        q.pop();

        int x,y;
        cin >> x >> y;

        Node* leftNode;
        Node* rightNode;

        if(x == -1){
            leftNode = NULL;
        }
        else{
            leftNode = new Node(x);
        }
        if(y == -1){
            rightNode = NULL;
        }
        else{
            rightNode = new Node(y);
        }

        front->left = leftNode;
        front->right = rightNode;

        if(leftNode != NULL){
            q.push(leftNode);
        }
        if(rightNode != NULL){
            q.push(rightNode);
        } 
    }
    return root;
}

void pre_order(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    pre_order(root->left);
    pre_order(root->right);
}


int main(){
      
    Node* root = inputTree();
    
    pre_order(root);

    return 0;
}