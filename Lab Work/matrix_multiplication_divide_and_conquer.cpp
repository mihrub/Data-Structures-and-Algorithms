#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

long long multiplications = 0;
long long additions = 0;

vector<vector<long long>> addMatrix(vector<vector<long long>> a, vector<vector<long long>> b){
    int n = a.size();
    vector<vector<long long>> c(n, vector<long long>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            c[i][j] = a[i][j] + b[i][j];
            additions++;
        }
    }
    return c;
}

vector<vector<long long>> matrixMultiplicationDC(vector<vector<long long>> a, vector<vector<long long>> b){
    int n = a.size();
    if(n == 1){
        multiplications++;
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

    vector<vector<long long>> c11 = addMatrix(matrixMultiplicationDC(a11, b11), matrixMultiplicationDC(a12, b21));
    vector<vector<long long>> c12 = addMatrix(matrixMultiplicationDC(a11, b12), matrixMultiplicationDC(a12, b22));
    vector<vector<long long>> c21 = addMatrix(matrixMultiplicationDC(a21, b11), matrixMultiplicationDC(a22, b21));
    vector<vector<long long>> c22 = addMatrix(matrixMultiplicationDC(a21, b12), matrixMultiplicationDC(a22, b22));

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

    ifstream inFile("input.txt");
    if(!inFile){
        cout << "Error: Could not open input.txt" << endl;
        return 1;
    }

    int testCases;
    inFile >> testCases;

    while(testCases--){
        int size;
        inFile >> size;

        cout << "==========================================" << endl;
        cout << "(NxN) Matrix: " << size << "x" << size << endl;

        vector<vector<long long>> a;
        for(int i = 0; i < size; i++){
            vector<long long> v;
            for(int j = 0; j < size; j++){
                long long val;
                inFile >> val;
                v.push_back(val);
            }
            a.push_back(v);
        }

        vector<vector<long long>> b;
        for(int i = 0; i < size; i++){
            vector<long long> v;
            for(int j = 0; j < size; j++){
                long long val;
                inFile >> val;
                v.push_back(val);
            }
            b.push_back(v);
        }

        multiplications = 0;
        additions = 0;

        vector<vector<long long>> c = matrixMultiplicationDC(a, b);

            cout << "Matrix C : " << endl;
            for(auto v : c){
                for(auto it : v){
                    cout << it << " ";
                }
                cout << endl;
            }

        cout << "\n--- Operation Analysis ---" << endl;
        cout << "Multiplications : " << multiplications << " (N^3)" << endl;
        cout << "Additions       : " << additions << " (N^3 - N^2)" << endl;
        cout << "Total Ops       : " << (multiplications + additions) << " (2 * N^3 - N^2)" << endl;
        cout << "Time Complexity : O(N^3)\n" << endl;
    }

    inFile.close();
    return 0;
}