class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) 
    {
        long long no_of_ways = 0;
        for(int no_of_pens = 0; no_of_pens*cost1 <= total; no_of_pens++)
        {
            int remaining_budget = total - no_of_pens*cost1;
            
            int no_of_pencils = remaining_budget/cost2;
            
            no_of_ways += no_of_pencils + 1;
        }
        
        return no_of_ways;
    }
};
