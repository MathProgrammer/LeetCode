#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTrees(int n) {

        vector <int> no_of_trees_of_size(n + 1, 0);

        for(int tree_i = 0; tree_i <= n; tree_i++)
        {
            if(tree_i <= 1)
                no_of_trees_of_size[tree_i] = 1;
            else
            {
                for(int left_subtree_size = 0; left_subtree_size <= tree_i - 1; left_subtree_size++)
                {
                    int no_of_left_subtrees = no_of_trees_of_size[left_subtree_size];
                    int no_of_right_subtrees = no_of_trees_of_size[tree_i - 1 - left_subtree_size];

                    no_of_trees_of_size[tree_i] += no_of_left_subtrees*no_of_right_subtrees;
                }
            }
        }

        return no_of_trees_of_size[n];
    }
};
