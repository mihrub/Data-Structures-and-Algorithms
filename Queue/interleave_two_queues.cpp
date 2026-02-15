#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int main(){

    queue<int> q;
    int n;
    cin >> n;

    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        q.push(x);
    }

    int half = n/2;

    queue<int> qq;
    while(half--){
        qq.push(q.front());
        q.pop();
    }

    while(!q.empty()){

        int a = qq.front();
        qq.push(a);
        qq.pop();

        int b = q.front();
        qq.push(b);
        q.pop();

    }

    while(!qq.empty()){
        cout << qq.front() << " ";
        qq.pop();
    }
    cout << endl;
      
    return 0;
}