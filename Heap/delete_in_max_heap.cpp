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
        int parent_index = (current_index - 1)/2;
        if(v[current_index] > v[parent_index])
            swap(v[current_index],v[parent_index]);
        else    
            break;
        current_index = parent_index;        
    }
}

void print(vector<int> v){
    for(int a : v){
        cout << a << " ";
    }
    cout << endl;
}

void erase(vector<int> &v){
    v[0] = v.back();
    v.pop_back();
    int current_index = 0;

    while(true){

    int left_child_index = 2 * current_index + 1;
    int right_child_index = 2 * current_index + 2;

    int left_value = INT_MIN;
    int right_value = INT_MIN;

    if(left_child_index < v.size()){
        left_value = v[left_child_index];
    }
    if(right_child_index < v.size()){
        right_value = v[right_child_index];
    }

    if(left_value >= right_value && left_value > v[current_index]){
        swap(v[left_child_index],v[current_index]);
        current_index = left_child_index;
    }
    else if(right_value > left_value && right_value > v[current_index]){
        swap(v[right_child_index],v[current_index]);
        current_index = right_child_index;
    }
    else{
        break;
    }
    }
}


int main(){

    int n;
    cin >> n;
      
    vector<int> v;

    for(int i = 0; i<n; i++){
        int val;
        cin >> val;
        insert(v,val);
    }

    print(v);
    erase(v);
    print(v);


    return 0;
}