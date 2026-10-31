#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;

struct Node{
    char ch;
    int freq;
    Node *left;
    Node *right;
    Node(char ch, int freq, Node *l = nullptr, Node *r = nullptr){
        this->ch = ch;
        this->freq = freq;
        this->left = l;
        this->right = r;
    }
};

struct Compare{
    bool operator()(Node *a, Node *b){
        return a->freq > b->freq;
    }
};

void generateCodes(Node *root, string code, unordered_map<char,string> &codes){
    if(!root){
        return;
    }
    if(!root->left && !root->right){
        codes[root->ch] = code.empty() ? "0" : code;
        return; 
    }
    generateCodes(root->left,code + "0",codes);
    generateCodes(root->right,code + "1",codes);
}

Node *buildHuffmanTree(vector<char> &chars, vector<int> &freq){
    priority_queue<Node*,vector<Node*>,Compare> pq;
    for(int i = 0; i<chars.size(); i++){
        pq.push(new Node(chars[i],freq[i]));
    }
    while(pq.size() > 1){
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        Node *merged = new Node('\0',left->freq + right->freq,left,right);
        pq.push(merged); 
    }
    return pq.top();
}

int main(){

    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> chars(n);
    vector<int> freq(n);

    for(int i = 0; i<n; i++){
        cout << "Enter character and frequency " << i + 1 << ": ";
        cin >> chars[i] >> freq[i];
    }

    Node* root = buildHuffmanTree(chars, freq);
    unordered_map<char, string> codes;
    generateCodes(root, "", codes);
    cout << "\nCharacter\tFrequency\tCode\n";
    
    for(int i = 0; i<n; i++){
        cout << chars[i] << "\t\t" << freq[i] << "\t\t" << codes[chars[i]] << endl;
    }

    return 0;
}