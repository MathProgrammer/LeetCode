class Solution {
public:
    
    void remove(multiset <int> &M, int n)
    {
        M.erase(M.find(n));
    }
    
    void greedy_remove(multiset <int> &main_M, multiset <int> &remaining_M, long long &value_sum, int n)
    {
        if(remaining_M.count(n) > 0)
        {
            remove(remaining_M, n);
        }
        else 
        {
            remove(main_M, n); 
            value_sum -= n; 
            
            int smallest_remaining = *remaining_M.begin(); 
            remove(remaining_M, smallest_remaining);
            
            main_M.insert(smallest_remaining); 
            value_sum += smallest_remaining;
        }
    }
    
    void greedy_insert(multiset <int> &main_M, multiset <int> &remaining_M, long long &value_sum, int n)
    {
        int largest_in_main_M = *main_M.rbegin();
        if(largest_in_main_M >= n)
        {
            remove(main_M, largest_in_main_M);
            value_sum -= largest_in_main_M; 
            
            remaining_M.insert(largest_in_main_M);
            
            main_M.insert(n); 
            value_sum += n;
        }
        else 
        {
            remaining_M.insert(n); 
        }
    }
    
    long long minimumCost(vector<int>& nums, int k, int dist) 
    {     
        const long long oo = 1e15;
        long long answer = oo;
        
        long long value_sum = 0;
        
        multiset <int> smallest_elements, remaining; 
        for(int i = nums.size() - 1; i >= 1; i--)
        {
            if(smallest_elements.size() < k - 2)
            {
                smallest_elements.insert(nums[i]);
                value_sum += nums[i];
            }
            else if(smallest_elements.size() == k - 2)
            {
                if(i + dist + 1 <= nums.size() - 1)
                {
                    greedy_remove(smallest_elements, remaining, value_sum, nums[i + dist + 1]);
                }
                
                long long answer_here = nums[0] + nums[i] + value_sum;
                answer = min(answer, answer_here);
                
                greedy_insert(smallest_elements, remaining, value_sum, nums[i]);
            }
        }
        
        return answer;
    }
};
