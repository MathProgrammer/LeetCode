#include <vector> 

using namespace std; 

class Solution 
{
    private: 
    int min(int x, int y)
    {
        return (x < y ? x : y);
    }
    
    int square(int n)
    {
        return n*n;
    }

    int get_c(int d, int r)
    {
        int left = 0, right = d + 1; 
        while(right - left > 1)
        {
            int mid = (left + right)/2; 
            if(square(mid) + square(r) <= square(d))
            {
                left = mid;
            }
            else 
            {
                right = mid;
            }
        }

        return left;
    }

    long long get_sum(vector <long long> &sum, int i, int c_range)
    {
        int left = max(0, i - c_range); 
        int right = min(sum.size() - 1, i + c_range);

        const int MOD = 1e9 + 7;
        long long range_sum = sum[right] - (left == 0 ? 0 : sum[left - 1]);
        range_sum += MOD; 
        range_sum %= MOD;
        
        return range_sum;
    }

public:
    int numberOfRoutes(vector<string>& grid, int d) 
    {
        const int MOD = 1e9 + 7;
        int rows = grid.size(), columns = grid[0].size(); 
        vector <vector <int> > up_paths(rows, vector <int> (columns, 0));
        vector <vector <int> > no_of_paths(rows, vector <int> (columns, 0));
        vector <vector <long long> > prefix_sum(rows, vector <long long> (columns, 0));
        vector <vector <long long> > prefix_sum_up(rows, vector <long long> (columns, 0));

        const char BLOCK = '#', FREE = '.';
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < columns; c++)
            {
                if(grid[r][c] == BLOCK)
                {
                    continue;
                }

                if(r == 0)
                {
                    up_paths[r][c] = 1;
                    continue;
                }

                int c_range = get_c(d, 1);
                up_paths[r][c] = get_sum(prefix_sum[r - 1], c, c_range);
            }

            for(int c = 0; c < columns; c++)
            {
                prefix_sum_up[r][c] = up_paths[r][c] + (c == 0 ? 0 : prefix_sum_up[r][c - 1]);
                prefix_sum_up[r][c] %= MOD;
            }

            for(int c = 0; c < columns; c++)
            {
                if(grid[r][c] == BLOCK)
                {
                    continue;
                }
                
                int c_range = get_c(d, 0);
                no_of_paths[r][c] = get_sum(prefix_sum_up[r], c, c_range);
            }

            for(int c = 0; c < columns; c++)
            {
                prefix_sum[r][c] = no_of_paths[r][c] + (c == 0 ? 0 : prefix_sum[r][c - 1]);
                prefix_sum[r][c] %= MOD;
            }
        }

        long long answer = prefix_sum[rows - 1][columns - 1];
        return answer;
    }
};