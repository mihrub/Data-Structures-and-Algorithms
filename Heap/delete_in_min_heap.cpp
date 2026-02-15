#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

void insert(vector<int> &v, int val){
    v.push_back(val);
    int current_index = v.size() - 1;

    while(current_index != 0){
        int parent_index = (current_index - 1) / 2;
        if(v[current_index] < v[parent_index]){
            swap(v[current_index],v[parent_index]);
            current_index = parent_index;
        }
        else
            break;
    }
}

void erase(vector<int> &v){
    v[0] = v.back();
    v.pop_back();
    int current_index = 0;
    while(true){

    int left_child_index = 2 * current_index + 1;
    int right_child_index = 2 * current_index + 2;
    int left_value = INT_MAX;
    int right_value = INT_MAX;

    if(left_child_index < v.size()){
        left_value = v[left_child_index];
    }
    if(right_child_index < v.size()){
        right_value = v[right_child_index];
    }

    if(left_value >= right_value && left_value < v[current_index]){
        swap(v[left_child_index],v[current_index]);
        current_index = left_child_index;
    }
    else if(right_value > left_value && right_value < v[current_index]){
        swap(v[right_child_index],v[current_index]);
        current_index = right_child_index;
    }
    else{
        break;
    }
    }
}

void print(vector<int> v){
    for(int x : v){
        cout << x << " ";
    }
    cout << endl;
}


int main(){

    int n;
    cin >> n; // 12

    vector<int> v; // 1 3 5 7 9 11 13 15 17 19 21 4

    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        insert(v,x);
    }
    print(v);
    erase(v);
    print(v);
    erase(v);
    print(v);
      
    return 0;
}