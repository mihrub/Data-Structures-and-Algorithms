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

static int index = -1;

Node* buildNodes(vector<int> nodes){
    index++;

    if(nodes[index] == -1){
        return NULL;
    }

    Node* currentNode = new Node(nodes[index]);

    currentNode->left = buildNodes(nodes);
    currentNode->right = buildNodes(nodes);

    return currentNode;
}

void PreOrder_Traversal(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    PreOrder_Traversal(root->left);
    PreOrder_Traversal(root->right);
}

int main(){
      
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildNodes(nodes);

    PreOrder_Traversal(root);

    return 0;
}