#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

void adaptiveSort(vector<int> &vec,int n){
    
    int max_elem = *max_element(vec.begin(),vec.end());
    int min_elem = *min_element(vec.begin(),vec.end());

    int r = max_elem - min_elem + 1;

    cout << "Maximum Element: " << max_elem << endl;
    cout << "Minimum Element: " << min_elem << endl;
    cout << "R : " << r << endl;

    if(r <= 2 * n){
        int x = 0;
        vector<int> freq(max_elem + 1, 0);
        for (int i = 0; i < n; i++){
            freq[vec[i]]++;
            x++;
        }
        for (int i = 1; i <= max_elem; i++){
            freq[i] += freq[i - 1];
            x++;
        }
        vector<int> ans(n, -1);
        for (int i = n - 1; i >= 0; i--){
            ans[--freq[vec[i]]] = vec[i];
            x++;
        }

        cout << "Selected Algorithm : Counting Sort" << endl;
        cout << "Sorted Array: ";
        for(auto it : ans){
            cout << it << " ";
        }
        cout << endl;
        cout << "Frequency Array Size : " << max_elem << endl;
        cout << "Time Complexity : " << x << endl;
        cout << "Auxiliary Space Complexity : O(n+R)" << endl;
    }

    else {

        int x = 0;
        int y = 0;
        for(int i = 1; i < n; i++){
            int j = i;
            y++;
            while (j && vec[j] < vec[j - 1]){
                swap(vec[j], vec[j - 1]);
                x++;
                j--;
            }
        }
        cout << "Selected Algorithm : Insertion Sort" << endl;
        cout << "Sorted Array: ";
        for(auto it : vec){
            cout << it << " ";
        }
        cout << endl;
        cout << "Key Comparisons : " << x << endl;
        cout << "Time Complexity : " << x+y << endl;
        cout << "Auxiliary Space Complexity : O(1)" << endl;
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i<n; i++){
        cin >> v[i];
    }

    adaptiveSort(v,n);

    return 0;
}