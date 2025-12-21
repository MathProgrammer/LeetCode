#include <vector> 
#include <map>
#include <algorithm>

using namespace std;

class Solution 
{
    public:
    #define all(v) (v).begin(), (v).end()
    int minSwaps(vector<int>& nums, vector<int>& forbidden) 
    {
        map <int, int> frequency, forbidden_frequency;
        for(int i = 0; i < nums.size(); i++)
        {
            frequency[nums[i]]++; 
            forbidden_frequency[forbidden[i]]++;
        }

        const int NOT_POSSIBLE = -1;
        for(int n : nums)
        {
            int allowed_spots = nums.size() - forbidden_frequency[n];
            if(frequency[n] > allowed_spots)
            {
                return NOT_POSSIBLE;
            }
        }

        map <int, int> pair_frequency;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == forbidden[i])
            {
                pair_frequency[nums[i]]++;
            }
        }

        vector <pair <int, int> > forbidden_pairs;
        for(auto it = pair_frequency.begin(); it!= pair_frequency.end(); it++)
        {
            forbidden_pairs.push_back(make_pair(it->second, it->first));
        }

        sort(all(forbidden_pairs));
        reverse(all(forbidden_pairs));
        
        int swaps = 0, forbidden_pairs_till_here = 0;
        for(int i = 0; i < forbidden_pairs.size(); i++)
        {
            int forbidden_pairs_here = forbidden_pairs[i].first;
            int swaps_here = min(forbidden_pairs_here, forbidden_pairs_till_here);

            swaps += swaps_here; 
            forbidden_pairs_here -= swaps_here;
            forbidden_pairs_till_here -= swaps_here;
            
            forbidden_pairs_till_here += forbidden_pairs_here;
        }

        swaps += forbidden_pairs_till_here;
        
        return swaps;
    }
};