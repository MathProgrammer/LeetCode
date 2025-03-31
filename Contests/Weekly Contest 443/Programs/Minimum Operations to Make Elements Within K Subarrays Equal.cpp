#include <vector> 
#include <set>

using namespace std;
class Solution 
{
    private: 
        void balance(multiset <int> &L, multiset <int> &R, long long &left_sum, long long &right_sum)
        {
            while(R.size() > L.size())
            {
                int n = *R.begin(); 
                R.erase(R.find(n));
                right_sum -= n;

                L.insert(n);
                left_sum += n;
            }

            while(L.size() > R.size() + 1)
            {
                int n = *L.rbegin(); 
                L.erase(L.find(n));
                left_sum -= n;

                R.insert(n);
                right_sum += n;
            }
        }

        void insert(int n, multiset <int> &L, multiset <int> &R, long long &left_sum, long long &right_sum)
        {
            if(L.size() == 0 || n < *L.rbegin())
            {
                //cout << "Inserting " << n << " in left\n";
                L.insert(n);
                left_sum += n;
            }
            else 
            {
                //cout << "Inserting " << n << " in right\n";
                R.insert(n);
                right_sum += n;
            }

            balance(L, R, left_sum, right_sum);
        }

        void erase(int n, multiset <int> &L, multiset <int> &R, long long &left_sum, long long &right_sum)
        {//cout << "Erasing " << n << "\n";
            if(L.count(n) > 0)
            {
                L.erase(L.find(n));
                left_sum -= n;
            }
            else 
            {
                R.erase(R.find(n));
                right_sum -= n;
            }

            balance(L, R, left_sum, right_sum);
        }

        int get_median(multiset<int> &L, multiset <int> &R)
        {
            if(L.size()%2 == R.size()%2)
            {
                return (*L.rbegin() + *R.begin())/2;
            }
            else 
            {
                return *L.rbegin();
            }
        }

    public:
    long long minOperations(vector<int>& nums, int subarray_size, int no_of_subarrays) 
    {
        int minimum = nums[0];
        for(int i = 0; i < nums.size(); i++)
        {
            minimum = min(nums[i], minimum);
        }

        if(minimum < 0)
        {
            for(int i = 0; i < nums.size(); i++)
            {
                nums[i] += 2*abs(minimum);
            }
        }
        
        vector <long long> sum(nums.size() + 1); 
        for(int i = 0; i < nums.size(); i++)
        {
            sum[i] = nums[i] + (i == 0 ? 0 : sum[i - 1]);
        }
        
        vector <long long> median_operations(nums.size());
        multiset <int> first_half, second_half; 
        long long left_sum = 0, right_sum = 0;
        for(int left = 0, right = 0; right < nums.size();)
        {
            while(right - left < subarray_size)
            {
                insert(nums[right], first_half, second_half, left_sum, right_sum); 
                right++;
            }

            long long median = get_median(first_half, second_half); 
            median_operations[right - 1] = (first_half.size()*median - left_sum) + (right_sum - second_half.size()*median);

            erase(nums[left], first_half, second_half, left_sum, right_sum); 
            left++;
        }

        const long long oo = 1e15; 
        vector <vector <long long> > minimum_cost(nums.size() + 1, vector <long long> (no_of_subarrays + 1, oo));
        for(int i = 0; i < nums.size(); i++)
        {
            for(int k = 0; k <= no_of_subarrays; k++)
            {
                if(k == 0)
                {
                    minimum_cost[i][k] = 0; 
                    continue;
                }
                
                if(i + 1 < subarray_size*k)
                {
                    break;
                }

                long long subarray_sum = sum[i] - (i - subarray_size < 0 ? 0 : sum[i - subarray_size]);
                long long operations_here = median_operations[i];

                if(k == 1 && i == subarray_size - 1)
                {
                    minimum_cost[i][k] = operations_here;
                    continue;
                }

                minimum_cost[i][k] = min(minimum_cost[i - 1][k], operations_here + minimum_cost[i - subarray_size][k - 1]);
            }
        }

        long long answer = oo;
        for(int i = 0; i < nums.size(); i++)
        {
            answer = min(answer, minimum_cost[i][no_of_subarrays]);
        }

        return answer;
    }
};