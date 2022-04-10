class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) 
    {
        sort(flowers.begin(), flowers.end());
        
        vector <long long> suffix_cost(flowers.size() + 1, 0);
        for(int i = flowers.size() - 1; i >= 0; i--)
        {
            if(suffix_cost[i + 1] > newFlowers)
            {
                suffix_cost[i] = suffix_cost[i + 1];
                continue;
            }
            
            suffix_cost[i] = max(0, target - flowers[i]) + suffix_cost[i + 1];
        }
        
        vector <long long> prefix_cost(flowers.size(), 0);
        for(int i = 1; i < flowers.size(); i++)
        {
            if(prefix_cost[i - 1] > newFlowers)
            {
                prefix_cost[i] = prefix_cost[i - 1];
                continue;
            }
            
            long long prefix_value = flowers[i - 1];
            long long prefix_size = i;
            
            prefix_cost[i] = prefix_cost[i - 1] + (flowers[i] - prefix_value)*prefix_size;
        }
        
        long long answer = 0;
        if(suffix_cost[0] <= newFlowers)
        {
            answer = flowers.size()*1LL*full; 
        }
        
        for(int i = flowers.size(); i >= 1; i--)
        {
            if(suffix_cost[i - 1] == 0)
            {
                continue;
            }
            
            if(suffix_cost[i] > newFlowers)
            {
                break;
            }
            
            long long remaining_flowers = newFlowers - suffix_cost[i];
            
            int best_partial = upper_bound(prefix_cost.begin(), prefix_cost.end(), remaining_flowers) - prefix_cost.begin() - 1; 
            best_partial = min(best_partial, i - 1);
            
            long long best_partial_value = flowers[best_partial];
            long long number_of_full_gardens = flowers.size() - i;
            
            long long prefix_remaining_flowers = remaining_flowers - prefix_cost[best_partial];
            long long prefix_size = best_partial + 1;
            
            best_partial_value += (prefix_remaining_flowers/prefix_size);
            
            best_partial_value = min(best_partial_value, target*1LL - 1);
            
            long long answer_here = full*number_of_full_gardens + partial*best_partial_value;
            
            answer = max(answer, answer_here);
        }
        
        return answer;
    }
};
