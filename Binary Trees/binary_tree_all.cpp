/*
             10
           /   \
         20     30
        /  \    / \
       40  50  60 70
      /       /
    80       90
     \        \
      100     110

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

void preorder_traversal(Node* root){
    if(root  == NULL){
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

void levelorder_traversal(Node* root){
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        cout << front->data << " ";
        if(front->left != NULL){
            q.push(front->left);
        }
        if(front->right != NULL){
            q.push(front->right);
        }
    }
}

Node* inputTree(){
    int x;
    cin >> x;
    Node* root = new Node(x);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        int x,y;
        cin >> x >> y;
        Node* myLeft, *myRight;
        if(x == -1){
            myLeft = NULL;
        }
        else{
            myLeft = new Node(x);
        }
        if(y == -1){
            myRight = NULL;
        }
        else{
            myRight = new Node(y);
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

int countNode(Node* root){
    if(root == NULL){
        return 0;
    }
    int l = countNode(root->left);
    int r = countNode(root->right);
    return l+r+1;
}

int maxHeight(Node* root){
    if(root == NULL){
        return 1;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    int l = maxHeight(root->left);
    int r = maxHeight(root->right);
    return max(l,r) + 1;
}

int countLeafNodes(Node* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    int l = countLeafNodes(root->left);
    int r = countLeafNodes(root->right);
    return l+r;
}

int sumofNodes(Node* root){
    if(root == NULL){
        return 0;
    }
    int l = sumofNodes(root->left);
    int r = sumofNodes(root->right);
    int current = l+r+root->data;
    cout << "Sum : " << current << endl;
    return l+r+root->data;
}   

int main(){
      
    Node* root = inputTree();

    // Input : 10 20 30 40 50 60 70 80 -1 -1 -1 90 -1 -1 -1 -1 100 -1 110 -1 -1 -1 -1

    cout << "Pre Order : \n";
    preorder_traversal(root);
    cout << endl;

    cout << "In Order : \n";
    inorder_traversal(root);
    cout << endl;

    cout << "Post Order : \n";
    postorder_traversal(root);
    cout << endl;

    cout << "Level Order : \n";
    levelorder_traversal(root);
    cout << endl;
    
    cout << "Total Nodes : " << countNode(root) << endl;
    cout << "Max Height : " << maxHeight(root) << endl;
    cout << "Count Leaf Nodes : " << countLeafNodes(root) << endl;
    cout << "Sum of Nodes : " << sumofNodes(root) << endl;
    

    return 0;
}