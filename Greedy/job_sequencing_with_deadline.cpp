#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Job{
    char id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b){
    return a.profit > b.profit;
}

void jobScheduling(vector<Job> &jobs, int n){
    sort(jobs.begin(),jobs.end(),compare);
    vector<int> slot(n,-1);
    for(int i = 0; i<n; i++){
        for(int j = min(n,jobs[i].deadline) - 1; j >= 0; j--){
            if(slot[j] == -1){
                slot[j] = i;
                break;
            }
        }
    }
    int totalProfit = 0;
    cout << "Scheduled Jobs: ";
    for (int i = 0; i < n; i++) {
        if (slot[i] != -1) {
            cout << jobs[slot[i]].id << " ";
            totalProfit += jobs[slot[i]].profit;
        }
    }
    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main(){

    vector<Job> jobs = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},{'d', 1, 25}, {'e', 3, 15}};
    int n = jobs.size();
    
    jobScheduling(jobs,n);
    
    return 0;
}