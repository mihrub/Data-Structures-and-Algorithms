#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

vector<int> countSort(vector<int> &v){
    int min_ele = *min_element(v.begin(),v.end());
    for(int i = 0; i<v.size(); i++){
        v[i] -= min_ele;
    }
    for(auto it: v){
        cout << it << " ";
    }
    cout << endl;
    int max_ele = *max_element(v.begin(),v.end());
    vector<int> freq(max_ele+1,0);
    for(int i = 0; i<v.size(); i++){
        freq[v[i]]++;
    }
    for(int i = 1; i<freq.size(); i++){
        freq[i] += freq[i-1];
    }
    vector<int> ans(v.size(),0);
    for(int i = v.size()-1; i>=0; i--){
        ans[--freq[v[i]]] = v[i];
    }
    for(int i = 0; i<ans.size(); i++){
        ans[i] += min_ele;
    }
    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v = {5,-4,1,-2,2,9,6,-1,0,-1,2};
    auto ans = countSort(v);
    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;

    return 0;
}