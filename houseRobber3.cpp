class Solution {
public:
    vector<int> solve(TreeNode* root)
    {
       if(root == nullptr)
       {
           return {0, 0};
       }
       vector<int> left = solve(root->left);
       vector<int> right = solve(root->right);

       int include = root->val + left[1] + right[1];
       int exclude = max(left[0], left[1]) + max(right[0], right[1]);
       return {include, exclude};
    }

    int rob(TreeNode* root) {
        vector<int> result = solve(root);
        return max(result[0], result[1]);
    }
};
//https://www.youtube.com/watch?v=hVEpCEWAb6Q  nice explain
