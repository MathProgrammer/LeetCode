#include <vector> 
#include <algorithm> 

using namespace std; 

class Solution 
{
    private: 
    struct Segment
    {
        int ones, zeroes, length; 

        Segment(int Ones, int Zeroes)
        {
            ones = Ones; 
            zeroes = Zeroes; 
            length = ones + zeroes;
        }
    };

    static int sort_by_ones(Segment &L, Segment &R)
    {
        if(L.zeroes == 0 && R.zeroes == 0)
        {
            return (L.length < R.length);
        }
        
        if(L.zeroes == 0)
        {
            return true;
        }

        if(R.zeroes == 0)
        {
            return false;
        }
        
        if(L.ones == R.ones)
        {
            return (L.length < R.length);
        }

        //cout << "Verict is " << (L.ones < R.ones) << " L = " << L.ones << " R = " << R.ones << "\n";
        return (L.ones > R.ones);
    }

    long long power_mod(long long x, long long power, int mod)
    {
        long long answer = 1; 
        while(power > 0)
        {
            if(power%2 == 1)
            {
                answer = (answer*x)%mod;
            }

            x = (x*x)%mod; 
            power = power/2;
        }

        return answer;
    }
    
    public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) 
    {
        vector <Segment> segments; 
        for(int i = 0; i < nums1.size(); i++)
        {
            segments.push_back(Segment(nums1[i], nums0[i]));
        }

        sort(segments.begin(), segments.end(), sort_by_ones);
        vector <int> suffix_sum(segments.size() + 1, 0); 
        for(int i = segments.size() - 1; i >= 0; i--)
        {
            suffix_sum[i] = segments[i].length + suffix_sum[i + 1];
        }
        
        const int MOD = 1e9 + 7;    
        int answer = 0; 
        for(int i = 0; i < segments.size(); i++)
        {
            long long value_of_1s_here = power_mod(2, segments[i].ones, MOD);
            value_of_1s_here += MOD - 1;
            value_of_1s_here %= MOD;

            long long bits_after = segments[i].zeroes + suffix_sum[i + 1];
            long long suffix_contribution = power_mod(2, bits_after, MOD);

            int contribution = (value_of_1s_here*suffix_contribution)%MOD;

            answer += contribution; 
            answer %= MOD;
        }

        return answer;
    }
};