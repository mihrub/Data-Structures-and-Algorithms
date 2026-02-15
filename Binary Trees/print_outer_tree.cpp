#include <bits/stdc++.h>
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
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        int a,b; 
        cin >> a >> b;
        Node* myLeft,*myRight;
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

void print_left_tree(Node* root){
    if(root == NULL){
        return;
    }
    print_left_tree(root->left);
    if(root->left == NULL)
        print_left_tree(root->right);
    cout << root->data << " ";
}

void print_right_tree(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";    
    if(root->right == NULL){
        print_right_tree(root->left);
    }
    print_right_tree(root->right);
}

void print_node1(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";    
    print_node1(root->left);
    print_node1(root->right);
}

void print_node2(Node* root){
    if(root == NULL){
        return;
    } 
    print_node2(root->left);
    print_node2(root->right);  
    cout << root->data << " ";         
}

void merge_two_node(Node* root){
    if(root->left != NULL && root->right != NULL){
        print_left_tree(root->left);
        cout << root->data << " ";
        print_right_tree(root->right);
    }
    else if(root->left == NULL && root->right != NULL){
        print_node1(root);
    }
    else if(root->right == NULL && root->left != NULL){
        print_node2(root);
    }
    else{
        cout << root->data << endl;
    }
}

int main()
{
    Node* root = inputTree();
    if(root == NULL){
        cout << " ";
        return 0;
    }
    merge_two_node(root);

    return 0;
}

