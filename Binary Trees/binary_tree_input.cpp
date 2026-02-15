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

Node* input_tree(){
    int x;
    cin >> x;
    Node* root; 
    if(x == -1)
        root = NULL;
    else
        root = new Node(x);
    queue<Node*> q;
    if(root != NULL)
        q.push(root);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        int a,b;
        cin >> a >> b;
        Node* myLeft,*myRight;

        if(a == -1)
            myLeft = NULL;
        else
            myLeft = new Node(a);
        if(b == -1)
            myRight = NULL;
        else    
            myRight = new Node(b); 
            
        front->left = myLeft;
        front->right = myRight;

        if(front->left != NULL)
            q.push(front->left);
        if(front->right != NULL)
            q.push(front->right);   
    }
    return root;
}

int main(){
    Node* root = input_tree();
    

    return 0;
}