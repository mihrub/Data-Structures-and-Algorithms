#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
int main(){
      
    int n;
    cin >> n; // 11

    vector<int> v(n);  // 1 3 5 7 9 11 13 15 17 19 21

    for(int i = 0; i<n; i++){
        cin >> v[i];
    }

    int x;
    cin >> x; // 4

    v.push_back(x);

    int current_index = v.size() - 1;

    while(current_index != 0){
        int parent_index = (current_index - 1)/2;
        if(v[parent_index] > v[current_index])
            swap(v[parent_index],v[current_index]);
        else    
            break;
        current_index = parent_index;
    }

    for(int a : v){
        cout << a << " ";
    }
    cout << endl;

    return 0;
}