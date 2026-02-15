#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

void Tower_Of_Hanoi(int n,char source,char helper,char destination){
    if(n == 1){
        cout << n << " Transfered to " << source << " to " << destination << endl;
        return;
    }
    Tower_Of_Hanoi(n-1,source,destination,helper);
    cout << n << " Transfered to " << source << " to " << destination << endl;
    Tower_Of_Hanoi(n-1,helper,source,destination);
}

int main(){
      
    Tower_Of_Hanoi(4,'A','B','C');

    return 0;
}