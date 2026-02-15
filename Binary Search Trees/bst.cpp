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

void print(Node* root){
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

bool search(Node* root,int value){   // Best Case / Average Case - O(logn) --- Wrost Case - O(n) -- So, Final = O(Height)
    if(root == NULL){
        return false;
    }
    if(root->data == value){
        return true;
    }
    if(root->data > value){
        return search(root->left,value);
    }
    else{
        return search(root->right,value);
    }
}

int main(){
    
    Node* root = inputTree();  // 18 7 21 -1 12 20 26 9 15 -1 -1 -1 -1 -1 -1 -1 -1
    print(root);
    int value;
    cout << "Value : ";
    cin >> value;
    if(search(root,value)){
        cout << "Found" << endl;
    }
    else{
        cout << "Not Found" << endl;
    }
    
    return 0;
}