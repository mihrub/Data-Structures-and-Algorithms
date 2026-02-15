#include <iostream>
#include <chrono>
#include<queue>
using namespace std;
using namespace std::chrono;

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
    int a;
    cin >> a;
    if(a == -1){
        return NULL;
    }
    Node* root = new Node(a);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){

        Node* front = q.front();
        q.pop();

        int x,y;
        cin >> x >> y;

        Node* leftNode;
        Node* rightNode;

        if(x == -1){
            leftNode = NULL;
        }
        else{
            leftNode = new Node(x);
        }
        if(y == -1){
            rightNode = NULL;
        }
        else{
            rightNode = new Node(y);
        }

        front->left = leftNode;
        front->right = rightNode;

        if(leftNode != NULL){
            q.push(leftNode);
        }
        if(rightNode != NULL){
            q.push(rightNode);
        } 
    }
    return root;
}

void level_order(Node* root){
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

int main() {
    // Record start time
    auto start = high_resolution_clock::now();

    // ----- Code to measure -----
    Node* root = inputTree();
    level_order(root);
    // ---------------------------

    // Record end time
    auto end = high_resolution_clock::now();

    // Calculate duration in milliseconds
    auto duration = duration_cast<nanoseconds>(end - start);
    auto measure_time = duration_cast<milliseconds>(end-start);

    cout << "Execution Time: " << measure_time.count() << " ms" << endl;
    cout << "Execution Time: " << duration.count() << " ns" << endl;

    return 0;
}
