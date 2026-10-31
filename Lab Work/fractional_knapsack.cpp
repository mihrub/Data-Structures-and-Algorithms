#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<time.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

vector<Item> generate(int n){
    srand(time(nullptr));
    vector<Item> items(n);
    for(int i = 0; i<n; i++){
        items[i].weight = rand() % 200 + 1;
        items[i].value = rand() % 200 + 1;
    }
    return items;
}

bool comp(Item a, Item b){
    double r1 = (double)a.value / a.weight;
    double r2 =  (double)b.value / b.weight;
    return r1 > r2;
}

double fractional_knapsack(vector<Item> items, int capacity){
    sort(items.begin(),items.end(),comp);   
    double total = 0.0;
    for(auto &item : items){
        if(item.weight <= capacity){
            total += item.value;
            capacity -= item.weight;
        }
        else{
            total += item.value * ((double)capacity / item.weight);
        }
    }
    return total;
}

int main(){
    
    vector<int> n = {5,10,15,20};
    int count = 1;

    for(auto x : n){
        vector<Item> items = generate(x);
        cout << "Number of item : " << x << endl;
        cout << "Item " << count <<  " : " << endl;
        for(auto it : items){
            cout << "Weight : " << it.weight << " , " << "Value : " << it.value << endl;
        }
        count++;
        srand(time(nullptr));
        int capacity =  rand() % 100;

        cout << "Maximum value in Knapsack : " << fractional_knapsack(items,capacity) << endl; 
        cout << endl;   
    }
    
    return 0;
}