#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector <vector<int> > new_image;
    vector <vector<int> > visited;

    int no_of_rows, no_of_columns;
    int original_colour, new_colour;

    int is_inside(int x, int y)
    {
        return (x >= 0 && x < no_of_rows && y >= 0 && y < no_of_columns);
    }

    void fill(int x, int y)
    {
        if(new_image[x][y] != original_colour) return;

        new_image[x][y] = new_colour;
        visited[x][y] = true;

        if(is_inside(x + 1, y) && !visited[x + 1][y]) fill(x + 1, y);
        if(is_inside(x - 1, y) && !visited[x - 1][y]) fill(x - 1, y);
        if(is_inside(x, y + 1) && !visited[x][y + 1]) fill(x, y + 1);
        if(is_inside(x, y - 1) && !visited[x][y - 1]) fill(x, y - 1);
    }

    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {

        new_image = image;
        no_of_rows = image.size(); no_of_columns = image[0].size();

        visited = vector <vector <int> >(no_of_rows, vector <int>(no_of_columns, false));

        original_colour = image[sr][sc];
        new_colour = newColor;

        fill(sr, sc);

        return new_image;

    }
};
