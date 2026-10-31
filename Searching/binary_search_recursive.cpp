#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

int binarySearch(vector<int> &v, int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (v[mid] == x)
            return mid;

        if (v[mid] > x)
            return binarySearch(v, low, mid - 1, x);

        return binarySearch(v, mid + 1, high, x);
    }
  return -1;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v = {1,2,5,14,20,70};
    int size = v.size();
    int key = 2;
    cout << binarySearch(v,0,size-1,key) << endl;
    
    return 0;
}