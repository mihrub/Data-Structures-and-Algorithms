#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

int ackermann(int m, int n){
    if(m == 0){
        return n+1;
    }
    else if(m > 0 && n == 0){
        return ackermann(m-1,1);
    }
    else if(m > 0 && n > 0){
        return ackermann(m-1,ackermann(m,n-1));
    }
    return 0;
}

int main(){
      
    int m,n;
    cin >> m >> n;

    int a = ackermann(m,n);
    cout << a << endl;

    return 0;
}