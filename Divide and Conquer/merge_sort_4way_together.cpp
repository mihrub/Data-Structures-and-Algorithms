#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void merge4(int arr[], int si, int mid1, int mid2, int mid3, int ei){
    vector<int> temp;
    int i = si;       
    int j = mid1 + 1; 
    int k = mid2 + 1; 
    int l = mid3 + 1;

    while(i <= mid1 || j <= mid2 || k <= mid3 || l <= ei){
        int vi = (i <= mid1) ? arr[i] : INT_MAX;
        int vj = (j <= mid2) ? arr[j] : INT_MAX;
        int vk = (k <= mid3) ? arr[k] : INT_MAX;
        int vl = (l <= ei)   ? arr[l] : INT_MAX;

        if(vi <= vj && vi <= vk && vi <= vl){
            temp.push_back(arr[i++]);
        }
        else if(vj <= vi && vj <= vk && vj <= vl){
            temp.push_back(arr[j++]);
        }
        else if(vk <= vi && vk <= vj && vk <= vl){
            temp.push_back(arr[k++]);
        }
        else{
            temp.push_back(arr[l++]);
        }
    }

    for(int idx = si, x = 0; idx <= ei; idx++){
        arr[idx] = temp[x++];
    }
}

void mergeSort4Together(int arr[], int si, int ei){
    if(si >= ei){
        return;
    }

    int len = ei - si + 1;
    int mid1 = si + len/4 - 1;
    int mid2 = si + 2*len/4 - 1;
    int mid3 = si + 3*len/4 - 1;

    mergeSort4Together(arr, si, mid1);
    mergeSort4Together(arr, mid1+1, mid2);
    mergeSort4Together(arr, mid2+1, mid3);
    mergeSort4Together(arr, mid3+1, ei);

    merge4(arr, si, mid1, mid2, mid3, ei);
}

int main(){

    int arr[] = {100,20,10,40,20,50,70,30,90,80};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Unsorted Array: ";

    for(int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;    
    mergeSort4Together(arr,0,size-1);

    cout << "Sorted Array: ";
    for(int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
