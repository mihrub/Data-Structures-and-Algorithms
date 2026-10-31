#include<iostream>
#include<vector>
using namespace std;

vector<vector<long long>> matrixMultiplicationItr(vector<vector<int>> a, vector<vector<int>> b){
    int n = a.size();
    int m = a[0].size();
    int p = b[0].size();
    vector<vector<long long>> c(n, vector<long long>(p, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < p; j++){
            for(int k = 0; k < m; k++){
                c[i][j] += (long long)a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

int main(){

    int n,m,p;
    cin >> n >> m;

    vector<vector<int>> a;
    for(int i = 0; i<n; i++){
        vector<int> v;
        for(int j = 0; j < m; j++){
            int val;
            cin >> val;
            v.push_back(val);
        }
        a.push_back(v);
    }
    
    cin >> m >> p;
    
    vector<vector<int>> b;
    for (int i = 0; i<m; i++){
        vector<int> v;
        for (int j = 0; j<p; j++){
            int val;
            cin >> val;
            v.push_back(val);
        }
        b.push_back(v);
    }

    vector<vector<long long>> c = matrixMultiplicationItr(a, b);

    for(auto itr : c){
        for(auto it : itr){
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}