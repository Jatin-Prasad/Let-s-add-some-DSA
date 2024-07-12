#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Step 1: Sort the input array
        
        set<vector<int>> uniqueSubsets;  // Step 2: Use a set to store unique subsets
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++) {
            vector<int> subset;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    subset.push_back(nums[j]);
                }
            }
            uniqueSubsets.insert(subset);
        }

        vector<vector<int>> ans(uniqueSubsets.begin(), uniqueSubsets.end());  // Step 3: Convert set to vector
        return ans;
    }
};
