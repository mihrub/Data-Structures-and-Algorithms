/*
Problem Statement
You are given an N×N grid. Let (i,j) denote the cell in the i-th row from the top and the j-th column from the left.
The state of each cell is described by N strings S1, S2, …, SN, each of length N.
If the j-th character of Si is '@', then cell (i,j) contains one coin. If it is '.', then the cell is empty.
You start at cell (1,1). It is guaranteed that (1,1) is empty.

You may perform the following action any number of times (including zero):
Let your current position be (i,j). Move to either the right cell (i,j+1) or the down cell (i+1,j). You cannot move outside the grid. If the destination cell contains a coin, you must pick it up.

For each x = 0, 1, …, 2N-2, solve the following:
After performing some actions (possibly zero), you reach a cell (i,j) while having exactly x coins. How many possible cells (i,j) are there?

Constraints
- 2 ≤ N ≤ 4000
- S1, S2, …, SN are strings of length N consisting of '@' and '.'
- The first character of S1 is '.'
- N is an integer

Partial Score
This problem has partial scoring.
If you solve the dataset with N ≤ 1500, you will get 2 points.

Input
The input is given from standard input in the following format:
N
S1
S2
⋮
SN

Output
Print 2N-1 lines. On the i-th line, output the answer for x = i-1.

Sample 1
Input:
3
.@@
..@
@..

Output:
5
6
3
2
0

Explanation: 
For example, when x=0, the possible cells (i,j) are (1,1), (2,1), (2,2), (3,2), (3,3), so there are 5 such cells.

Sample 2
Input:
7
...@@@.
..@@@@@
@...@..
..@..@.
.....@@
.@@@@@@
@@.@.@.

Output:
15
29
28
23
19
13
6
5
3
0
0
0
0
*/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // L[j] / U[j] = min / max coins collectible on a path ending at
    // the current row, column j (rolling arrays — only one row kept)
    vector<int> prevL(n + 1, 0), prevU(n + 1, 0);
    vector<int> curL(n + 1, 0), curU(n + 1, 0);

    // diff[x] is a difference array: diff[L]++ and diff[U+1]--
    // marks that coin count x is achievable for x in [L, U]
    vector<long long> diff(2 * n + 2, 0);

    for(int i = 1; i <= n; i++){
        string row;
        cin >> row;
        row = " " + row;   // shift so row[j] matches 1-indexed j

        for(int j = 1; j <= n; j++){
            int coin = (row[j] == '@') ? 1 : 0;
            int L, U;

            if(i == 1 && j == 1){
                L = U = 0;
            }
            else if(i == 1){
                // only reachable from the left
                L = curL[j - 1] + coin;
                U = curU[j - 1] + coin;
            }
            else if(j == 1){
                // only reachable from above
                L = prevL[j] + coin;
                U = prevU[j] + coin;
            }
            else{
                L = min(prevL[j], curL[j - 1]) + coin;
                U = max(prevU[j], curU[j - 1]) + coin;
            }

            curL[j] = L;
            curU[j] = U;

            diff[L]++;
            diff[U + 1]--;
        }

        prevL = curL;
        prevU = curU;
    }

    long long running = 0;
    for(int x = 0; x <= 2 * n - 2; x++){
        running += diff[x];
        cout << running << "\n";
    }

    return 0;
}