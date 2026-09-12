#include <vector> 
#include <map> 
#include <set>

using namespace std; 

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) 
    {
        map <int, int> previous, frequency;
        map <int, set <int> > distances;
        for(int i = 0; i < nums.size(); i++)
        {
            if(previous.count(nums[i]) != 0)
            {
                distances[nums[i]].insert(i - previous[nums[i]]);
            }
            
            previous[nums[i]] = i;
            frequency[nums[i]]++;
        }

        int special_elements = 0;
        for(auto it = distances.begin(); it != distances.end(); it++)
        {
            int n = it->first;
            if(distances[n].size() == 1 && frequency[n] >= 3)
            {
                special_elements++;
            }
        }

        return special_elements;
    }
};