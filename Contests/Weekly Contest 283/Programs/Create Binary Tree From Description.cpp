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
    
    void complete(TreeNode* v, unordered_map <int, int> &L, unordered_map <int, int> &R)
    {
        int value = v->val;
        if(L[value] != 0)
        {
            v->left = new TreeNode(L[value]);
            complete(v->left, L, R);
        }
        
        if(R[value] != 0)
        {
            v->right = new TreeNode(R[value]);
            complete(v->right, L, R);
        }
    }
    
    int get_root(vector <vector <int> > &descriptions)
    {
        set <int> vertices; 
        for(int i = 0; i < descriptions.size(); i++)
        {
            vertices.insert(descriptions[i][0]);
        }
        
        for(int i = 0; i < descriptions.size(); i++)
        {
            int child = descriptions[i][1];
            if(vertices.count(child) == 1)
            {
                vertices.erase(child);
            }
        }
        
        return *vertices.begin();
    }
    
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
    {
        unordered_map <int, int> right_child, left_child; 
        for(int i = 0; i < descriptions.size(); i++)
        {
            int parent = descriptions[i][0], child = descriptions[i][1];
            const int IS_LEFT = 1;
            if(descriptions[i][2] == IS_LEFT)
            {
                left_child[parent] = child;
            }
            else 
            {
                right_child[parent] = child;
            }
        }
        
        int root = get_root(descriptions);
        TreeNode* R = new TreeNode(root);
        complete(R, left_child, right_child);
        
        return R;
    }
};
