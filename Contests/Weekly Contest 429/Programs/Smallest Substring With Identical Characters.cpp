#include <algorithm> 
#include <string> 
using namespace std; 

class Solution 
{
    public:
    int no_of_operations(string &S, int max_streak)
    {
        int operations = 0, streak = 1; 
        for(int i = 1; i < S.size(); i++)
        {
            if(S[i] == S[i - 1])
            {
                streak++;
            }

            if(i == S.size() - 1 || S[i] != S[i - 1])
            {
                operations += streak/(max_streak + 1);
                streak = 1;
            }
        }

        return operations;
    }

    int get_current_max_streak(string &S)
    {
        int streak = 1, max_streak = 1;
        for(int i = 1; i < S.size(); i++)
        {
            streak = (S[i] == S[i - 1] ? streak + 1 : 1);
            max_streak = max(max_streak, streak);
        }

        return max_streak;
    }

    int is_alternating_possible(string &S, int max_flips)
    {
        int flips_01 = 0; 
        for(int i = 0; i < S.size(); i++)
        {
            flips_01 += (S[i] != i%2 + '0');
        }

        int flips_10 = 0; 
        for(int i = 0; i < S.size(); i++)
        {
            flips_10 += (S[i] == i%2 + '0');
        }

        return (min(flips_01, flips_10) <= max_flips);
    }

    int minLength(string &S, int numOps) 
    {
        if(is_alternating_possible(S, numOps))
        {
            return 1;
        }
        
        int left = 1, right = get_current_max_streak(S);
        //L < Answer <= R
        while(right - left > 1)
        {
            int mid = (left + right)/2; 
            if(no_of_operations(S, mid) <= numOps)
            {
                right = mid;
            }
            else 
            {
                left = mid;
            }
        }

        return right;
    }
};