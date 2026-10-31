#include<iostream>
#include<vector>
using namespace std;

vector<vector<long long>> addMatrix(vector<vector<long long>> a, vector<vector<long long>> b){
    int n = a.size();
    vector<vector<long long>> c(n, vector<long long>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
}

vector<vector<long long>> subMatrix(vector<vector<long long>> a, vector<vector<long long>> b){
    int n = a.size();
    vector<vector<long long>> c(n, vector<long long>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    return c;
}

vector<vector<long long>> matrixMultiplicationStrassen(vector<vector<long long>> a, vector<vector<long long>> b){
    int n = a.size();
    if(n == 1){
        return {{(long long)a[0][0] * b[0][0]}};
    }

    int k = n / 2;
    vector<vector<long long>> a11(k, vector<long long>(k)), a12(k, vector<long long>(k)),
                              a21(k, vector<long long>(k)), a22(k, vector<long long>(k));
    vector<vector<long long>> b11(k, vector<long long>(k)), b12(k, vector<long long>(k)),
                              b21(k, vector<long long>(k)), b22(k, vector<long long>(k));

    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            a11[i][j] = a[i][j];
            a12[i][j] = a[i][j + k];
            a21[i][j] = a[i + k][j];
            a22[i][j] = a[i + k][j + k];

            b11[i][j] = b[i][j];
            b12[i][j] = b[i][j + k];
            b21[i][j] = b[i + k][j];
            b22[i][j] = b[i + k][j + k];
        }
    }

    vector<vector<long long>> m1 = matrixMultiplicationStrassen(addMatrix(a11, a22), addMatrix(b11, b22));
    vector<vector<long long>> m2 = matrixMultiplicationStrassen(addMatrix(a21, a22), b11);
    vector<vector<long long>> m3 = matrixMultiplicationStrassen(a11, subMatrix(b12, b22));
    vector<vector<long long>> m4 = matrixMultiplicationStrassen(a22, subMatrix(b21, b11));
    vector<vector<long long>> m5 = matrixMultiplicationStrassen(addMatrix(a11, a12), b22);
    vector<vector<long long>> m6 = matrixMultiplicationStrassen(subMatrix(a21, a11), addMatrix(b11, b12));
    vector<vector<long long>> m7 = matrixMultiplicationStrassen(subMatrix(a12, a22), addMatrix(b21, b22));

    
    vector<vector<long long>> c11 = addMatrix(subMatrix(addMatrix(m1, m4), m5), m7);
    vector<vector<long long>> c12 = addMatrix(m3, m5);
    vector<vector<long long>> c21 = addMatrix(m2, m4);
    vector<vector<long long>> c22 = addMatrix(subMatrix(addMatrix(m1, m3), m2), m6);

    vector<vector<long long>> c(n, vector<long long>(n, 0));
    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            c[i][j] = c11[i][j];
            c[i][j + k] = c12[i][j];
            c[i + k][j] = c21[i][j];
            c[i + k][j + k] = c22[i][j];
        }
    }

    return c;
}

int main(){

    int size;
    cin >> size;

    vector<vector<long long>> a;
    for(int i = 0; i<size; i++){
        vector<long long> v;
        for(int j = 0; j<size; j++){
            long long val;
            cin >> val;
            v.push_back(val);
        }
        a.push_back(v);
    }

    vector<vector<long long>> b;
    for(int i = 0; i<size; i++){
        vector<long long> v;
        for (int j = 0; j<size; j++){
            long long val;
            cin >> val;
            v.push_back(val);
        }
        b.push_back(v);
    }

    vector<vector<long long>> c = matrixMultiplicationStrassen(a, b);

    for(auto itr : c){
        for(auto it : itr){
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}