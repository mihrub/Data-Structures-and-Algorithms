#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

void print_array(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++){
        int j = i;
        while (j && arr[j] < arr[j - 1]){
            swap(arr[j], arr[j - 1]);
            print_array(arr, n);
            j--;
        }
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[] = {100, 20, 10, 40, 20, 50, 70, 30, 90, 80};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}