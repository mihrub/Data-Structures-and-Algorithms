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
        root = NULL;
    }
    else{
        root = new Node(x);
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        int a,b;
        cin >> a >> b;
        Node* myLeft, *myRight;
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

void print(Node* root){ // Best Case - O(logn) --- Worst Case - O(n*n) --- Final = O(Height)
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
    cout << endl;
}

void insert(Node* &root,int value){
    if(root == NULL){
        root = new Node(value);
    }
    if(root->data > value){
        if(root->left == NULL){
            root->left = new Node(value);
        }
        else{
            insert(root->left,value);
        }
    }
    else{
        if(root->right == NULL){
            root->right = new Node(value);
        }
        else{
            insert(root->right,value);
        }
    }
}

int main(){
    
    Node* root = inputTree();  // 18 7 21 -1 12 20 26 9 15 -1 -1 -1 -1 -1 -1 -1 -1
    print(root);
    int value;
    cout << "Value : ";
    cin >> value;

    insert(root,value);

    print(root);
    
    return 0;
}