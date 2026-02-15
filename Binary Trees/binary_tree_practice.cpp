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

Node* buildTree(){
    int n;
    cin >> n;
    Node* root = new Node(n);
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        int a,b;
        cin >> a >> b;
        Node* leftNode, *rightNode;

        if(a == -1){
            leftNode = NULL;
        }
        else{
            leftNode = new Node(a);
        }
        if(b == -1){
            rightNode = NULL;
        }
        else{
            rightNode = new Node(b);
        }

        if(leftNode != NULL){
            q.push(leftNode);
        }
        if(rightNode != NULL){
            q.push(rightNode);
        }
        front->left = leftNode;
        front->right = rightNode;
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

void in_order(Node* root){
    if(root == NULL){
        return;
    }
    in_order(root->left);
    cout << root->data << " ";
    in_order(root->right);
}

void post_order(Node* root){
    if(root == NULL){
        return;
    }
    post_order(root->left);
    post_order(root->right);
    cout << root->data << " ";
}

void level_order(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* front = q.front();
        cout << front->data << " ";
        q.pop();
        if(front->left != NULL){
            q.push(front->left);
        }
        if(front->right != NULL){
            q.push(front->right);
        }
    }
}

int countNode(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftSide = countNode(root->left);
    int rightSide = countNode(root->right);
    return leftSide + rightSide + 1;
}

int sum(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftSum = sum(root->left);
    int rightSum = sum(root->right);
    return leftSum + rightSum + root->data;
}

int leafSum(Node* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return root->data;
    }
    int leftSum = leafSum(root->left);
    int rightSum = leafSum(root->right);
    return leftSum + rightSum;
}

int countLeafNode(Node* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    int leftSide = countLeafNode(root->left);
    int rightSide = countLeafNode(root->right);
    return leftSide + rightSide;
}

int maxHeight(Node* root){
    if(root == NULL){
        return 1;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    int leftSide = maxHeight(root->left);
    int rightSide = maxHeight(root->right);
    return max(leftSide,rightSide) + 1;
}

int maxNode(Node* root){
    if(root == NULL){
        return INT_MIN;
    }
    int leftSide = maxNode(root->left);
    int rightSide = maxNode(root->right);
    return max(max(leftSide,rightSide),root->data);
}

int minNode(Node* root){
    if(root == NULL){
        return INT_MAX;
    }
    int leftSide = minNode(root->left);
    int rightSide = minNode(root->right);
    return min(min(leftSide,rightSide),root->data);    
}
    vector<int> vec;
void print_leaf_node(Node* root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        vec.push_back(root->data);
        return;
    }
    print_leaf_node(root->left);
    print_leaf_node(root->right);
}

bool searchNode(Node* root,int data){
    if(root == NULL){
        return false;
    }
    if(root->data == data){
        return true;
    }
    bool leftSide = searchNode(root->left,data);
    bool rightSide = searchNode(root->right,data);
    return leftSide || rightSide;
}


int main(){
      
    Node* root = buildTree();

    cout << "Pre-Order : ";
    pre_order(root);
    cout << endl;

    cout << "In-Order : ";
    in_order(root);
    cout << endl;

    cout << "Post-Order : ";
    post_order(root);
    cout << endl;   
    
    cout << "Level-Order : ";
    level_order(root);
    cout << endl;

    cout << "Total Nodes : " << countNode(root) << endl;
    cout << "Total Sum : " << sum(root) << endl;
    cout << "Leaf Sum : " << leafSum(root) << endl;
    cout << "Total Leaf Nodes: " << countLeafNode(root) << endl;
    cout << "Max Height : " << maxHeight(root) << endl;
    cout << "Max Node : " << maxNode(root) << endl;
    cout << "Min Node : " << minNode(root) << endl;

    print_leaf_node(root);
    cout << "Leaf Nodes: ";
    for(int x : vec){
        cout << x << " ";
    }
    cout << endl;

    int data;
    cout << "Data : ";
    cin >> data;
    if(searchNode(root,data)){
        cout << "Search Result : Found" << endl;
    }
    else{
        cout << "Search Result : Not Found" << endl;
    }

    return 0;
}