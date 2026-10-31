#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

void bucketSort(float arr[],int n){

    vector<vector<float>> bucket(n);

    float max_ele = *(max_element(arr,arr+n)); 
    float min_ele = *(min_element(arr,arr+n));

    float range = (max_ele - min_ele) / n;

    for(int i = 0; i<n; i++){
        int index = (arr[i] - min_ele) / range;
        float diff = (arr[i] - min_ele) / range - index;
        if(diff == 0 && arr[i] != min_ele){
            bucket[index-1].push_back(arr[i]);
        }
        else{
            bucket[index].push_back(arr[i]);
        }
    }

    for(int i = 0; i<n; i++){
        if(!bucket[i].empty()){
            sort(bucket[i].begin(),bucket[i].end());
        }
    }

    int k = 0;
    for(int i = 0; i<bucket.size(); i++){
        for(int j = 0; j<bucket[i].size(); j++){
            arr[k++] = bucket[i][j];
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    float arr[] = {6.13,8.45,0.12,1.89,4.75,2.63,7.85,10.39};
    int size = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr,size);

    for(int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}