#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:

    int is_possible(vector <int> &stations, int k, double x)
    {
        int new_stations = 0;

        for(int i = 1; i < stations.size(); i++)
        {
            if(stations[i] - stations[i - 1] >= x)
            {
                new_stations += ceil((stations[i] - stations[i - 1])/x) - 1;
            }
        }

        return (new_stations <= k);
    }

    double minmaxGasDist(vector<int>& stations, int K)
    {
        double low = 0, high = stations.back() - stations[0];
        double mid = (low + high)/2, epsilon = 1e-6;

        while(low < high)
        {
            mid = (low + high)/2;

            if(is_possible(stations, K, mid))
            {
                if(!is_possible(stations, K, mid - epsilon))
                {
                    break;
                }
                else
                {
                    high = mid;
                }
            }
            else
            {
                low = mid;
            }
        }

        return mid;
    }
};
