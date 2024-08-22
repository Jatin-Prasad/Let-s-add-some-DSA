class Solution {
public:
    int solve2(vector<int>& nums, int n) {
        if (n == 1) return nums[0];  // Edge case: only one house

        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            int include = dp[i-2] + nums[i];
            int exclude = dp[i-1];
            dp[i] = max(include, exclude);
        }
        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;  // Edge case: no houses
        return solve2(nums, n);
    }
};
