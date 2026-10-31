/*
WAP that takes an array of size n and q queries as input. 
For each query you will be given a number. For each query you have to print ‘YES’ 
if the number is present in the array, otherwise print ‘No’. 
Solve this problem in an optimized way.
Sample input

5
6 3 2 1 8

4

1
5
2
9
Sample output

YES
NO
YES
NO

*/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

void binary_search_query(vector<int> arr,int key){
    int i = 0;
    int j = arr.size() - 1;
    bool flag = false;

    while(i<=j){
        int mid = (i+j)/2;

        if(arr[mid] == key){
            flag = true;
            break;
        }
        else if(arr[mid] < key)
            i = mid+1;

        else if (arr[i] > key)
            j = mid-1;
    }
    
    (flag)? cout << "YES" << endl : cout << "NO" << endl;
}

int main(){
      
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(),arr.end());

    int q;
    cin >> q;

    while(q--){
        int a;
        cin >> a;
        binary_search_query(arr,a);
    }

    return 0;
}