#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

vector<int> countSort(vector<int> &vec, int n){

    int m = *(max_element(vec.begin(),vec.end()));
    vector<int> freq(m+1,0);

    for(int i = 0; i<n; i++){
        freq[vec[i]]++;
    }

    for(int i = 1; i<=m; i++){
        freq[i] += freq[i-1];
    }

    vector<int> ans(n);

    for(int i = n-1; i >= 0; i--){
        ans[freq[vec[i]] - 1] = vec[i];
        freq[vec[i]]--;
    }

    return ans;

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> vec = {7,2,2,1,5,7,3};
    int n = vec.size();

    auto ans = countSort(vec,n);

    for (auto it : ans){
        cout << it << " ";
    }
    cout << endl;
    
    return 0;
}