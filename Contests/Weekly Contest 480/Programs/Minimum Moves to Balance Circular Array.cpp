#include <vector> 

using namespace std; 

class Solution {
public:
    long long minMoves(vector<int>& balance) 
    {
        long long sum = 0;
        int sink = -1; 
        for(int i = 0; i < balance.size(); i++)
        {
            if(balance[i] < 0)
            {
                sink = i; 
            }
            else 
            {
                sum += balance[i];
            }
        }

        if(sink == -1)
        {
            return 0;
        }
        
        if(sum < abs(balance[sink]))
        {
            return -1;
        }

        long long answer = 0; 
        int left = sink, right = sink, cost = 0; 
        while(balance[sink] < 0)
        {
            left = (left == 0 ? balance.size() - 1 : left - 1); 
            right = (right == balance.size() - 1 ? 0 : right + 1);
            cost++;

            int amount_added_left = min(abs(balance[sink]), balance[left]);
            balance[sink] += amount_added_left;
            
            int amount_added_right = min(abs(balance[sink]), balance[right]);
            balance[sink] += amount_added_right; 
            
            int amount_added = amount_added_left + amount_added_right;
            
            answer += amount_added*1LL*cost;
        }
        
        return answer;
    }
};