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
        left = NULL;
        right = NULL;
    }    
};

Node* input_nodes(){
    int x;
    cin >> x;
    Node* root = new Node(x);
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* front  = q.front();
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

        if(front->left != NULL){
            q.push(front->left);
        }
        if(front->right != NULL){
            q.push(front->right);
        }
    }
    return root;
}

int count_nodes(Node* root){
    int count  = 0;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        count++;
        if(front->left != NULL){
            q.push(front->left);
        }
        if(front->right != NULL){
            q.push(front->right);
        }
    }
    return count;
}

int main(){

    Node* root = input_nodes();
    cout << count_nodes(root) << endl;
    
    return 0;
}