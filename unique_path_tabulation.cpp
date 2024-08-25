class Solution {
public:
//tabulttion 
    int uniquePaths(int m, int n) {
        // Create a dp table initialized with 0s
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Iterate over the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Base case: The starting point has one unique path
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else {
                    int up = 0, left = 0;
                    if (i > 0) up = dp[i-1][j];  // Take the value from the cell above
                    if (j > 0) left = dp[i][j-1];  // Take the value from the cell to the left
                    dp[i][j] = up + left;  // Sum of paths from above and from the left
                }
            }
        }

        // The bottom-right corner will have the total number of unique paths
        return dp[m-1][n-1];
    }
};
