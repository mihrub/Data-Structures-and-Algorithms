#include <bits/stdc++.h>
using namespace std;

// arr[] has size N; matrix i has dimensions arr[i-1] x arr[i], for i = 1..N-1
// dp[i][j]    = min multiplications to compute matrices i..j
// split[i][j] = k at which the optimal split for i..j happens

long long solve(int i, int j, const vector<int>& arr,
                vector<vector<long long>>& dp, vector<vector<int>>& split)
{
    if (i >= j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    long long ans = LLONG_MAX;
    for (int k = i; k < j; k++)
    {
        long long cost = solve(i, k, arr, dp, split)
                       + solve(k + 1, j, arr, dp, split)
                       + 1LL * arr[i - 1] * arr[k] * arr[j];
        if (cost < ans)
        {
            ans = cost;
            split[i][j] = k;
        }
    }
    return dp[i][j] = ans;
}

void printParens(const vector<vector<int>>& split, int i, int j)
{
    if (i == j)
    {
        cout << "A" << i;
        return;
    }
    cout << "(";
    printParens(split, i, split[i][j]);
    printParens(split, split[i][j] + 1, j);
    cout << ")";
}

void printTable(const vector<vector<long long>>& dp, int n)
{
    cout << "DP table (rows = i, cols = j):\n";
    cout << setw(6) << " ";
    for (int j = 1; j <= n; j++) cout << setw(10) << j;
    cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        cout << setw(6) << i;
        for (int j = 1; j <= n; j++)
        {
            if (j < i) cout << setw(10) << "-";
            else if (i == j) cout << setw(10) << 0;
            else cout << setw(10) << dp[i][j];
        }
        cout << "\n";
    }
}

int main()
{
    int N;
    cout << "Enter N (size of dimension array): ";
    cin >> N;

    vector<int> arr(N);
    cout << "Enter dimensions: ";
    for (int i = 0; i < N; i++) cin >> arr[i];

    int n = N - 1;  // number of matrices
    if (n < 1)
    {
        cout << "Need at least one matrix (N >= 2).\n";
        return 0;
    }

    vector<vector<long long>> dp(N, vector<long long>(N, -1));
    vector<vector<int>> split(N, vector<int>(N, 0));

    long long result = solve(1, n, arr, dp, split);

    cout << "\n";
    printTable(dp, n);
    cout << "\nMinimum multiplications: " << result << "\n";
    cout << "Optimal parenthesization: ";
    printParens(split, 1, n);
    cout << "\n";
    return 0;
}

// Time: O(N^3), Space: O(N^2)