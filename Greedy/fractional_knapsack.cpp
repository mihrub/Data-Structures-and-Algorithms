#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool comparator(const pair<int,int> &a, const pair<int,int> &b){
    double a1 = (1.0 * a.first / a.second);
    double b1 = (1.0 * b.first / b.second);
    return a1 > b1;
}

double fractionalKnapsack(vector<pair<int,int>> &items, int k){
    sort(items.begin(),items.end(),comparator);  // O(n logn)
    double maxVal = 0.0;
    for(auto &item : items){
        int value = item.first;
        int weight = item.second;
        if(weight <= k){
            maxVal += value;
            k -= weight;
        }
        else{
            maxVal += ((double) value / weight) * k;
            break;
        }
    }
    return maxVal;
}

int main(){

    vector<pair<int,int>> items = {{60,10},{100,20},{120,30},{80,40},{150,15}};
    int k = 60;

    cout << fractionalKnapsack(items,k) << endl;

    return 0;
}