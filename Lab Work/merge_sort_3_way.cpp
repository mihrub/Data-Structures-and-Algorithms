#include <iostream>
#include <vector>
using namespace std;

long long a = 0; 

void merge3Way(int arr[], int si, int mid1, int mid2, int ei) {
    vector<int> temp;
    
    int i = si;         
    int j = mid1 + 1;   
    int k = mid2 + 1;   

    while (i <= mid1 && j <= mid2 && k <= ei) {
        if (arr[i] <= arr[j] && arr[i] <= arr[k]) {
            temp.push_back(arr[i++]);
        } 
        else if (arr[j] <= arr[i] && arr[j] <= arr[k]) {
            temp.push_back(arr[j++]);
        } 
        else {
            temp.push_back(arr[k++]);
        }
        a++;
    }

    while (i <= mid1 && j <= mid2) {
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i++]);            
        }
        else{
            temp.push_back(arr[j++]);
        }
        a++;
    }

    while (j <= mid2 && k <= ei) {
        if (arr[j] <= arr[k]){ 
            temp.push_back(arr[j++]);
        }
        else{
            temp.push_back(arr[k++]);
        }
        a++;
    }

    while (i <= mid1 && k <= ei){
        if (arr[i] <= arr[k]){
            temp.push_back(arr[i++]);
        }
        else{ 
            temp.push_back(arr[k++]);
        }
        a++;
    }

    while(i <= mid1){
        temp.push_back(arr[i++]); a++; 
    }

    while(j <= mid2){
        temp.push_back(arr[j++]); a++; 
    }

    while (k <= ei){ 
        temp.push_back(arr[k++]); a++; 
    }

    for (int idx = si, x = 0; idx <= ei; idx++) {
        arr[idx] = temp[x++];
        a++;
    }
}

void mergeSort3Way(int arr[], int si, int ei) {
    if (si >= ei) {
        a++;
        return;
    }

    int mid1 = si + (ei - si) / 3;
    int mid2 = si + 2 * (ei - si) / 3;
    a += 2;

    mergeSort3Way(arr, si, mid1);
    mergeSort3Way(arr, mid1 + 1, mid2);
    mergeSort3Way(arr, mid2 + 1, ei);

    merge3Way(arr, si, mid1, mid2, ei);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    mergeSort3Way(arr.data(), 0, n - 1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;   
    
    cout << "Number of Operations: " << a << endl;

    return 0;
}