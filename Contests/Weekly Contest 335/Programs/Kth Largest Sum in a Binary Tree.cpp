/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void dfs(TreeNode* v, int level, vector <long long> &level_sum)
    {
        if(level_sum.size() <= level)
        {
            level_sum.push_back(0);
        }
        
        level_sum[level] += v->val;
        
        if(v->left != NULL)
        {
            dfs(v->left, level + 1, level_sum);
        }
        
        if(v->right != NULL)
        {
            dfs(v->right, level + 1, level_sum);
        }
    }
    
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        vector <long long> level_sum;
        dfs(root, 0, level_sum);
        sort(level_sum.begin(), level_sum.end());
        reverse(level_sum.begin(), level_sum.end());
        return (level_sum.size() >= k ? level_sum[k - 1] : -1);
    }
};
