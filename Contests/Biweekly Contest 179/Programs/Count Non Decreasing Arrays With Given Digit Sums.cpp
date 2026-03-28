#include <vector> 
#include <algorithm> 

using namespace std; 

class Solution 
{
    #define all(v) (v).begin(), (v).end()
    
    private: 
    int max(int x, int y)
    {
        return (x > y ? x : y);
    }
    
    int get_digit_sum(int n)
    {
        int sum = 0; 
        while(n > 0)
        {
            sum += n%10; 
            n /= 10;
        }

        return sum;
    }
    
    public:
    int countArrays(vector<int>& digitSum) 
    {
        const int MAX_N = 5000, MAX_SUM = 50; 
        int max_integers_with_one_digit_sum = 0;
        vector <vector <int> > integers_with_sum(MAX_SUM + 1);
        for(int n = 0; n <= MAX_N; n++)
        {
            int digit_sum = get_digit_sum(n); 
            integers_with_sum[digit_sum].push_back(n);
            max_integers_with_one_digit_sum = max(max_integers_with_one_digit_sum, integers_with_sum[digit_sum].size());
        }

        const int MOD = 1e9 + 7;
        vector <vector <int> > no_of_ways(digitSum.size(), vector <int> (max_integers_with_one_digit_sum + 1));
        for(int i = digitSum.size() - 1; i >= 0; i--)
        {
            int current_sum = digitSum[i];
            
            for(int j = integers_with_sum[current_sum].size() - 1; j >= 0; j--)
            {
                if(j < integers_with_sum[current_sum].size() - 1)
                {
                    no_of_ways[i][j] = no_of_ways[i][j + 1];
                }
                
                if(i == digitSum.size() - 1)
                {
                    no_of_ways[i][j] += 1; 
                    continue;
                }

                int d1 = integers_with_sum[current_sum][j];
                int next_sum = digitSum[i + 1];
                int k = lower_bound(all(integers_with_sum[next_sum]), d1) - integers_with_sum[next_sum].begin(); 

                no_of_ways[i][j] += no_of_ways[i + 1][k];
                no_of_ways[i][j] %= MOD;
            }
        }

        int answer = integers_with_sum[digitSum[0]].size() > 0 ? 
                no_of_ways[0][0] : 
                0;

        return answer;
    }
};