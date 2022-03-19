class Solution {
public:
    int halveArray(vector<int>& nums) 
    {
        long long sum = 0;
        priority_queue <double> PQ;
        for(int i = 0; i < nums.size(); i++)
        {
            PQ.push(nums[i]);
            
            sum += nums[i];
        }
        
        double current_sum = 0;
        int operations = 0;
        while(current_sum*2 < sum)
        {
            double current = PQ.top();
            
            current_sum += current/2;
            PQ.pop();
            PQ.push(current/2);
            
            operations++;
        }
        
        return operations;
    }
};
