#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<set>
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

void collectAllLIS(int i, vector<vector<int>>& predecessors, const string& dna, vector<int>& path, set<string>& allLIS) {
    path.push_back(i);
    if(predecessors[i].empty()){
        string seq;
        for(int k = path.size() - 1; k >= 0; k--){
            seq += dna[path[k]];
        }
        allLIS.insert(seq);
    } 
    else{
        for(int p : predecessors[i]){
            collectAllLIS(p, predecessors, dna, path, allLIS);
        } 
    }
    path.pop_back();
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

    vector<int> dp(n, 1);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if (val[j] < val[i] && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
            }
        }
    }

    int maxLen = *max_element(dp.begin(), dp.end());

    vector<vector<int>> predecessors(n);
    for(int i = 0; i < n; i++){
        if(dp[i] == 1){
            continue;
        }
        for(int j = 0; j < i; j++){
            if (val[j] < val[i] && dp[j] == dp[i] - 1){
                predecessors[i].push_back(j);
            }
        }
    }

    set<string> allLIS;
    vector<int> path;
    for(int i = 0; i < n; i++){
        if(dp[i] == maxLen){
            collectAllLIS(i, predecessors, dna, path, allLIS);
        }
    }

    cout << "Length of Longest Increasing Subsequence = " << maxLen << endl;
    cout << "All Longest Increasing Subsequences (" << allLIS.size() << "):" << endl;

    for(const string& s : allLIS){
        cout << "  " << s << endl;
    }

    return 0;
}
