#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

int mapBase(char c) {
    switch (c) {
        case 'A': return 1;
        case 'C': return 2;
        case 'G': return 3;
        case 'T': return 4;
    }
    return 0;
}

int lisTable(vector<int>& val, vector<int>& dp, vector<int>& parent) {
    int n = val.size();
    dp.assign(n, 1);
    parent.assign(n, -1);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if (val[j] < val[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main(){

    string dna;
    cout << "Enter DNA sequence: ";
    cin >> dna;
    int n = dna.size();

    vector<int> val(n);
    for(int i = 0; i < n; i++){
        val[i] = mapBase(dna[i]);
    } 

    vector<int> dp, parent;
    int length = lisTable(val, dp, parent);

    int bestEnd = max_element(dp.begin(), dp.end()) - dp.begin();
    vector<int> indices;

    for(int i = bestEnd; i != -1; i = parent[i]){
        indices.push_back(i);
    }
    reverse(indices.begin(), indices.end());

    cout << "Length of Longest Increasing Subsequence = " << length << endl;
    cout << "One Longest Increasing Subsequence (bases): ";

    for(int idx : indices){
        cout << dna[idx] << " ";
    }

    cout << endl;

    return 0;
}