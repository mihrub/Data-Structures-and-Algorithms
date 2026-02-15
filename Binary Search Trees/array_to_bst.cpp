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

Node* convert(int arr[],int size,int l,int r){
    if(l>r){
        return NULL;
    }

    int mid = (l+r)/2;
    Node* root = new Node(arr[mid]);
    Node* leftRoot = convert(arr,size,l,mid-1);
    Node* rightRoot = convert(arr,size,mid+1,r);
    root->left = leftRoot;
    root->right = rightRoot;
    return root;
}

int main(){
    
    int n;
    cin >> n;
    int arr[n];

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    Node* root = convert(arr,n,0,n-1);
    print(root);

    return 0;
}