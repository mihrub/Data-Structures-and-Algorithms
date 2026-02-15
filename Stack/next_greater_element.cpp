#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<stack>
using namespace std;

void next_greater(vector<int> arr,vector<int> ans){
    stack<int> s;
    int index = arr.size()-1;
    ans[index] = -1;
    s.push(arr[index]);

    for(int i = index-1 ; i>=0 ; i--){
        int current = arr[i];
        while(!s.empty() && current >= s.top()){
            s.pop();
        }

        if(s.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = s.top();
        }
        s.push(current);
    }

    for(int j = 0; j<ans.size(); j++){
        cout << ans[j] << " ";
    }
    cout << endl;
}


int main(){
    
    vector<int> arr = {6,8,0,1,3};
    vector<int> ans(5,0);

    next_greater(arr,ans);

    return 0;
}