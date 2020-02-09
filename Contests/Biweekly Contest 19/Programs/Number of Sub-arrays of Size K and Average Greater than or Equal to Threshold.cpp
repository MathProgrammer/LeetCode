#include <vector>

using namespace std;
class Solution
{
    public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold)
    {
        //S[R] - S[L - 1] = K.R - K.(L - 1)
        vector <long long> sum(arr.size() + 5, 0);
        sum[0] = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            sum[i + 1] += sum[i] + arr[i];
        }
        
        int no_of_subarrays = 0;
        for(int i = k; i <= arr.size(); i++)
        {
            if(sum[i] - sum[i - k] >= k*threshold)
            {
                no_of_subarrays++;
            }
        }
        
        return no_of_subarrays;
    }
};
