#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

int main(){
      
    long long n;
    cin >> n;

    long long fibo[1005];
    memset(fibo,-1,sizeof(fibo));

    fibo[0] = 0;
    fibo[1] = 1;

    for(int i = 2; i<=n; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    cout << fibo[n] << endl;

    return 0;
}