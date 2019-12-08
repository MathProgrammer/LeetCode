#include <bits/stdc++.h>

using namespace std;

class Solution
{
    public:

    int rows, columns;

    int is_bit_set(int n, int bit)
    {
        return ( ( n& (1 << bit) ) != 0);
    }

    void display(int mask)
    {
        for(int i = 0; i < rows*columns; i++)
        {
            cout << (is_bit_set(mask, i) ? "1" : "0");

            if((i + 1)%columns == 0)
            {
                cout << "\n";
            }
        }
    }

    int flip_bit(int &n, int bit)
    {
        n ^= (1 << bit);

        return n;
    }

    int get_position(int i, int j)
    {
        return (i*columns + j);
    }

    int get_bitmask(vector < vector <int> > &M)
    {
        int mask = 0;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                if(M[i][j] == 1)
                {
                    mask |= (1 << get_position(i, j));
                }
            }
        }

        return mask;
    }



    int minFlips(vector < vector<int> >&M)
    {
        rows = M.size(), columns = M[0].size();

        queue <int> Q;
        map <int, int> moves_to;

        int starting_mask = get_bitmask(M);

        Q.push(starting_mask);

        const int NO_OF_NEIGHBOURS = 4;
        int neighbour_i[NO_OF_NEIGHBOURS] = {-1, 0, 0, 1};
        int neighbour_j[NO_OF_NEIGHBOURS] = {0, -1, 1, 0};

        while(!Q.empty())
        {
            int current_mask = Q.front();

            Q.pop();

            if(current_mask == 0)
            {
                return moves_to[current_mask];
            }

            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < columns; j++)
                {
                    int neighbour_mask = current_mask;

                    neighbour_mask = flip_bit(neighbour_mask, get_position(i, j));

                    for(int n = 0; n < NO_OF_NEIGHBOURS; n++)
                    {
                        int next_i = i + neighbour_i[n];
                        int next_j = j + neighbour_j[n];

                        if(0 <= next_i && next_i < rows && 0 <= next_j && next_j < columns)
                        {
                            int next_bit = get_position(next_i, next_j);

                            neighbour_mask = flip_bit(neighbour_mask, next_bit);
                        }
                    }

                    if(moves_to[neighbour_mask] == 0 && neighbour_mask != starting_mask)
                    {
                        Q.push(neighbour_mask);

                        moves_to[neighbour_mask] = moves_to[current_mask] + 1;
                    }
                }
            }
        }

        return -1;
    }
};
