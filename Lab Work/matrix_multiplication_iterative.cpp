#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

long long multiplications = 0;
long long additions = 0;

vector<vector<long long>> matrixMultiplicationItr(vector<vector<int>> a, vector<vector<int>> b){
    int n = a.size();
    vector<vector<long long>> c(n, vector<long long>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                c[i][j] += (long long)a[i][k] * b[k][j];
                multiplications++;
                additions++;
            }
        }
    }
    return c;
}

int main(){

    ifstream cin("input.txt");
    if(!cin){
        cout << "Error: input.txt not found!" << endl;
        return 1;
    }

    int testCases;
    cin >> testCases;

    while(testCases--){
        int size;
        cin >> size;

        vector<vector<int>> a;
        for(int i = 0; i < size; i++){
            vector<int> v;
            for(int j = 0; j < size; j++){
                int val;
                cin >> val;
                v.push_back(val);
            }
            a.push_back(v);
        }

        vector<vector<int>> b;
        for(int i = 0; i < size; i++){
            vector<int> v;
            for(int j = 0; j < size; j++){
                int val;
                cin >> val;
                v.push_back(val);
            }
            b.push_back(v);
        }

        multiplications = 0;
        additions = 0;

        vector<vector<long long>> c = matrixMultiplicationItr(a, b);

        cout << "==========================================" << endl;
        cout << "Result for Matrix Size: " << size << "x" << size << endl;
        cout << "==========================================" << endl;


        cout << "Matrix C : " << endl;
        for(auto v : c){
            for(auto it : v){
                cout << it << " ";
            }
                cout << endl;
        }

        cout << "\n--- Operation Analysis ---" << endl;
        cout << "Multiplications : " << multiplications << " (N^3)" << endl;
        cout << "Additions       : " << additions << " (N^3)" << endl;
        cout << "Total Ops       : " << (multiplications + additions) << " (2 * N^3)" << endl;
        cout << "Time Complexity : O(N^3)\n" << endl;
    }

    return 0;
}