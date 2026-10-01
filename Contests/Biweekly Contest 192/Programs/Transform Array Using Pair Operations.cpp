#include <vector> 
using namespace std; 

class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) 
    {
        long long source_sum = 0, target_sum = 0;
        for(int i = 0; i < source.size(); i++)
        {
            source_sum += source[i]; 
            target_sum += target[i];
        }

        return (source_sum == target_sum);
    }
};