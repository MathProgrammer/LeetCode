#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    struct Point
    {
        int x, y;

        Point(int X, int Y)
        {
            x = X, y = Y;
        }

        int operator<(const Point &P) const
        {
            return (x == P.x ? y < P.y : x < P.x);
        }

        Point operator+(const Point &P) const
        {
            return Point(x + P.x, y + P.y);
        }
    };

    int distance(Point P)
    {
        return (P.x*P.x + P.y*P.y);
    }

    int robotSim(vector<int>& commands, vector<vector<int> >& obstacles)
    {
        set <Point> forbidden;
        for(int i = 0; i < obstacles.size(); i++)
            forbidden.insert(Point(obstacles[i][0], obstacles[i][1]));

        const int NO_OF_DIRECTIONS = 4;
        const int POSITIVE_Y = 0, POSITIVE_X = 1, NEGATIVE_Y = 2, NEGATIVE_X = 3;
        vector <Point> step(NO_OF_DIRECTIONS, Point(0, 0));

        step[POSITIVE_Y] = Point(0, 1);
        step[POSITIVE_X] = Point(1, 0);
        step[NEGATIVE_Y] = Point(0, -1);
        step[NEGATIVE_X] = Point(-1, 0);

        int direction = POSITIVE_Y;
        Point location = Point(0, 0);
        int furthest_distance = 0;

        for(int i = 0; i < commands.size(); i++)
        {
            if(commands[i] < 0)
            {
                const int RIGHT = -1, LEFT = -2;

                if(commands[i] == RIGHT)
                    direction = (direction + 1)%NO_OF_DIRECTIONS; //anti-clockwise
                else if(commands[i] == LEFT)
                    direction = (direction - 1 + NO_OF_DIRECTIONS)%NO_OF_DIRECTIONS; //clockwise
            }
            else
            {
                for(int steps = 1; steps <= commands[i]; steps++)
                {
                    Point next_location = location + step[direction];

                    if(forbidden.count(next_location) == 1)
                    {
                        break;
                    }

                    location = next_location;
                }

                furthest_distance = max(furthest_distance, distance(location));
            }
        }

        return furthest_distance;
    }
};
