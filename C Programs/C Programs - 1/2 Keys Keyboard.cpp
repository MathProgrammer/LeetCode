#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int find_largest_factor_of(int n){

        for(int smallest_factor = 2; smallest_factor*smallest_factor <= n; smallest_factor++)
            if(n%smallest_factor == 0)
                return (n/smallest_factor);

        return n;
    }

    int minSteps(int n) {

        vector <int> minimum_steps_for(n + 1, 0);

        for(int i = 0; i <= n; i++)
        {
            if(i <= 1)
            {
                minimum_steps_for[i] = 0;
            }
            else
            {
                int largest_factor = find_largest_factor_of(i);

                if(largest_factor == i) //i is prime
                    minimum_steps_for[i] = i;
                else
                {
                    int no_of_copies = (i - largest_factor)/largest_factor; //largest_factor As are on screen
                    minimum_steps_for[i] = minimum_steps_for[largest_factor] + 1 + no_of_copies;
                }
            }
        }

        return minimum_steps_for[n];
    }
};
