#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int set[], int n, int sum) {
    // Create a 2D DP array with dimensions (n+1) x (sum+1)
    bool dp[n + 1][sum + 1];

    // If sum is 0, there is always a subset (the empty subset)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // If there are no elements and sum is not 0, there's no valid subset
    for (int j = 1; j <= sum; j++) {
        dp[0][j] = false;
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (set[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
            }
        }
    }

    // The answer is in the bottom-right corner of the table
    return dp[n][sum];
}

int main() {
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    
    if (isSubsetSum(set, n, sum)) {
        cout << "Found a subset with given sum" << endl;
    } else {
        cout << "No subset with given sum" << endl;
    }

    return 0;
}
