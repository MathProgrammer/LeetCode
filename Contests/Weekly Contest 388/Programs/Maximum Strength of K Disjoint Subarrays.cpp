#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int get_sign(int x)
    {
        return (x%2 == 1 ? 1 : -1);
    }

    long long maximumStrength(vector<int>& nums, int k)
    {
        int no_of_elements = nums.size();
        const long long oo = 1e18;
        vector <vector <long long> > maximum_strength(no_of_elements + 1, vector <long long> (k + 1, -oo));
        vector <long long> best_ending(k + 1, -oo);

        for(int i = 0; i < no_of_elements; i++)
        {
            for(int part_no = 1; part_no <= min(i + 1, k); part_no++)
            {
                long long coefficient = get_sign(part_no)*(k - part_no + 1LL);
                long long contribution = coefficient*nums[i];

                long long new_part_from_here = contribution + (part_no == 1 ? 0 : best_ending[part_no - 1]);
                long long adding_to_existing_part = (i + 1 == part_no ? -oo : contribution + maximum_strength[i - 1][part_no]);

                maximum_strength[i][part_no] = max(new_part_from_here, adding_to_existing_part);
            }

            for(int part_no = 1; part_no <= min(i + 1, k); part_no++)
            {
                best_ending[part_no] = max(best_ending[part_no], maximum_strength[i][part_no]);
            }

        }

        return best_ending[k];
    }
};
