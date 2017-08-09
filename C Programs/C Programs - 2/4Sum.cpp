#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {

        typedef vector <int> v_int;
        vector <v_int> solutions;
        set <v_int> solution_set;

        sort(all(nums));

        for(unsigned int start = 0; start < nums.size(); start++)
        {
            for(unsigned int end = start + 3; end < nums.size(); end++)
            {
                int pointer_1 = start + 1;
                int pointer_2 = end - 1;

                int a = nums[start], b = nums[end];
                int new_target = target - (a + b);

                while(pointer_1 < pointer_2)
                {
                    int c = nums[pointer_1], d = nums[pointer_2];

                    if(c + d == new_target)
                    {
                        v_int quadruple(4);
                        quadruple[0] = a;
                        quadruple[1] = b;
                        quadruple[2] = c;
                        quadruple[3] = d;

                        if(solution_set.count(quadruple) == 0)
                        {
                            solution_set.insert(quadruple);
                            solutions.push_back(quadruple);
                        }

                        pointer_1++;
                        pointer_2--;
                    }
                    else if(c + d > new_target)
                    {
                        pointer_2--;
                    }
                    else if(c + d < new_target)
                    {
                        pointer_1++;
                    }
                }
            }
        }

        return solutions;
    }
};
