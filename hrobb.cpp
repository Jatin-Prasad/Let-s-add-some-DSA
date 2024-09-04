class Solution {
public:
    int solve(vector<int>& nums, int n) {
        if (n == 1) return nums[0];  

        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            int include = nums[i] + dp[i - 2];
            int exclude = dp[i - 1];
            dp[i] = max(include, exclude);
        }
        return dp[n - 1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;  
        return solve(nums, n);
    }
};
