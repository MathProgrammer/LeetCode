#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution
{
public:
    bool hasPathSum(TreeNode* root, int sum) {

        if(root->left == NULL && root->right == NULL)
        {
            if(sum - root->val == 0)
                return true;
            else
                return false;
        }
        else
        {
            hasPathSum(root->left, sum - root->val);
            hasPathSum(root->right, sum - root->val);
        }

    }
};
