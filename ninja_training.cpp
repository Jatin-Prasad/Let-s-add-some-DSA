int f(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp) {
    if (day == 0) {
        int maxi = 0;
        for (int task = 0; task < 3; task++) {
            if (task != last) {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }

    // Check if the result is already computed
    if (dp[day][last] != -1) {
        return dp[day][last];
    }

    int maxi = 0;
    for (int task = 0; task < 3; task++) {
        if (task != last) {
            int point = points[day][task] + f(day - 1, task, points, dp);
            maxi = max(maxi, point);
        }
    }

    // Store the result in the dp table and return it
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>>& points) {
    // Initialize dp table with -1
    vector<vector<int>> dp(n, vector<int>(4, -1));

    // Start the recursion with the last day and last task as 3 (no task)
    return f(n - 1, 3, points, dp);
}
