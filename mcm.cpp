#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(int p[], int n) {
    int dp[n][n];

    // dp[i][j] = minimum cost to multiply matrices from i to j
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;   // cost of single matrix = 0

    // L = chain length
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n-1];
}

int main() {
    int p[] = {40, 20, 30, 10, 30};
    int n = sizeof(p) / sizeof(p[0]);

    cout << "Minimum multiplication cost = "
         << matrixChainMultiplication(p, n);

    return 0;
}

