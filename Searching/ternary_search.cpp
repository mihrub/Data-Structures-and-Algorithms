#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

bool ternarySearch(vector<int> &v, int x) {
    int l = 0;
    int r = v.size() - 1;

    while (l <= r){
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        if(v[mid1] == x || v[mid2] == x){
            return true;
        }

        if(x < v[mid1]){
            r = mid1 - 1;
        } 
        else if(x > v[mid2]){
            l = mid2 + 1;
        } 
        else{
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }

    return false;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v = {10,22,33,64,46};
    int x = 33;
    cout << (ternarySearch(v, x)? "true" : "false") << endl;

    v = {1, 3, 4, 5, 6};
    x = 0;
    cout << (ternarySearch(v, x)? "true" : "false") << endl;

    return 0;
}