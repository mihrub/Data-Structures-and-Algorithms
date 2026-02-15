/*
You will be given a positive integer N . You will start from 1 and do some steps (possibly zero).

In each step you can choose one of the following:

Add 3 with the current value
Multiply by 2 with the current value
Can you tell if you can reach N by using any number of steps you want.

Input Format:

First line will contain  T, the number of test cases.
In each test case you will be given N.

Output Format:

Print "YES" if you can reach N, "NO" otherwise.

Sample Input 0:

5
1
3
5
15
16

Sample Output 0:

YES
NO
YES
NO
YES

*/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
using namespace std; 

int dp[100005];

bool choice(int n){
    if(n == 1){
        return true;
    }
    if(n < 1){
        return false;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    bool l,r;
    if(n%2 == 0){
        l = choice(n/2);
    }
    else{
        r = choice(n-3);
    }
    return l || r;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i<=n; i++){
            dp[i] = -1;
        }
        if(choice(n)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
