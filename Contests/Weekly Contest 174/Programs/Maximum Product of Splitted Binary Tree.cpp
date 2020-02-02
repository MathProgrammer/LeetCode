#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;

 struct TreeNode
{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution
{
    public:
    map <TreeNode*, long long> sum;
    
    long long dfs_sum(TreeNode* root)
    {
        sum[root] = root->val;
        
        if(root->right != NULL)
        {
            sum[root] += dfs_sum(root->right);
        }
        
        if(root->left != NULL)
        {
            sum[root] += dfs_sum(root->left);
        }
        
        return sum[root];
    }
    
    int maxProduct(TreeNode* root)
    {
        dfs_sum(root);
        
        const int MOD = 1e9 + 7;
        
        dfs_sum(root);
        
        long long entire_sum = dfs_sum(root);
        long long answer = 0, minimum_difference = 1e15;
        
        stack <TreeNode*> S;
        S.push(root);
        
        while(!S.empty())
        {
            TreeNode* R = S.top();
            S.pop();
            
            if(R->right != NULL)
            {
                long long tree_2_sum = sum[R->right];
                long long tree_1_sum = entire_sum - tree_2_sum;

                if(abs(tree_2_sum - tree_1_sum) < minimum_difference)
                {
                    minimum_difference = abs(tree_2_sum - tree_1_sum);

                    answer = (tree_1_sum*tree_2_sum)%MOD;
                }

                S.push(R->right);
            }
        
            if(R->left != NULL)
            {
                long long tree_2_sum = sum[R->left];
                long long tree_1_sum = entire_sum - tree_2_sum;

                if(abs(tree_2_sum - tree_1_sum) < minimum_difference)
                {
                    minimum_difference = abs(tree_2_sum - tree_1_sum);

                    answer = (tree_1_sum*tree_2_sum)%MOD;
                }

                S.push(R->left);
            }
        }
        
        return answer;
    }
};
