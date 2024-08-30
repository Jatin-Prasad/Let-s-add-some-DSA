class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = make_pair(nums[i], i);
        }
        
        sort(a.begin(), a.end());
        
        int i = 0, j = n - 1;
        while (i < j) {
            int sum = a[i].first + a[j].first;
            if (sum == target) {
                return {a[i].second, a[j].second};
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        
        return {};
    }
};
