#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void merge3(int arr[], int si, int mid1, int mid2, int ei){
    vector<int> temp;
    int i = si;        
    int j = mid1 + 1; 
    int k = mid2 + 1;  

    while(i <= mid1 || j <= mid2 || k <= ei){

        int vi = (i <= mid1) ? arr[i] : INT_MAX;
        int vj = (j <= mid2) ? arr[j] : INT_MAX;
        int vk = (k <= ei)   ? arr[k] : INT_MAX;

        if(vi <= vj && vi <= vk){
            temp.push_back(arr[i++]);
        }
        else if(vj <= vi && vj <= vk){
            temp.push_back(arr[j++]);
        }
        else{
            temp.push_back(arr[k++]);
        }
    }

    for(int idx = si, x = 0; idx <= ei; idx++){
        arr[idx] = temp[x++];
    }
}

void mergeSort3Together(int arr[], int si, int ei){
    if(si >= ei){
        return;
    }

    int len = ei - si + 1;
    int mid1 = si + len/3 - 1;
    int mid2 = si + 2*len/3 - 1;

    mergeSort3Together(arr, si, mid1);
    mergeSort3Together(arr, mid1+1, mid2);
    mergeSort3Together(arr, mid2+1, ei);

    merge3(arr, si, mid1, mid2, ei);
}

int main(){

    int arr[] = {100,20,10,40,20,50,70,30,90,80};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Unsorted Array: ";

    for(int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;    
    mergeSort3Together(arr,0,size-1);

    cout << "Sorted Array: ";
    for(int i = 0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
