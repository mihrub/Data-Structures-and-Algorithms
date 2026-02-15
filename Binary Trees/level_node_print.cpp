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
    Node* root  = new Node(x);
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

void level_node(Node* root,int x){
    bool flag = false;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        Node* front = q.front().first;
        int level = q.front().second;
        q.pop();
        if(level == x){
            flag = true;
            cout << front->data << " ";
        }
        if(front->left != NULL){
            q.push({front->left,level+1});
        }
        if(front->right != NULL){
            q.push({front->right,level+1});
        }
    }
    if(!flag){
        cout << "Invalid" << endl;
    }
}


int main()
{
    Node* root = inputTree();
    int x;
    cin >> x;
    level_node(root,x);

    return 0;
}
