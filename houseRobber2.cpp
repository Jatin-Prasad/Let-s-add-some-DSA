class Solution {
public:
    int solve2(vector<int>& nums, int n) {
        if (n == 1) return nums[0];  // Edge case: only one house
        if (n == 0) return 0;        // Edge case: no houses
        
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
        if (n == 0) return 0;
        if (n == 1) return nums[0];  // Only one house, rob it

        // Two cases: 
        // 1. Rob houses from 0 to n-2 (i.e., first to second-last house)
        // 2. Rob houses from 1 to n-1 (i.e., second to last house)
        
        vector<int> first(nums.begin(), nums.end() - 1);  // Houses from 0 to n-2
        vector<int> second(nums.begin() + 1, nums.end()); // Houses from 1 to n-1
        
        return max(solve2(first, n-1), solve2(second, n-1));
    }
};
