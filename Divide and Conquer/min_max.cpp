#include<iostream>
using namespace std;

struct Pair{
    int min;
    int max;
};

Pair findMinMax(int arr[],int low, int high){
    Pair left,right,result;

    if(low == high){
        result.min = result.max = arr[high];
        return result;
    }

    if(high == low+1){
        if(arr[high] > arr[low]){
            result.max = arr[high];
            result.min = arr[low];
        }
        else{
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    int mid = (low + high) / 2;

    left = findMinMax(arr,0,mid);
    right = findMinMax(arr,mid+1,high);

    result.min = min(left.min,right.min);
    result.max = max(left.max,right.max);

    return result;
}

int main(){

    int n;
    cout << "Enter Number of Elements: ";
    cin >> n;

    int arr[n];
    cout << "Elements : ";
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    Pair result = findMinMax(arr,0,n-1);

    cout << "Min : " << result.min << endl;
    cout << "Max : " << result.max << endl;
       
    return 0;
}