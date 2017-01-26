
/*
    Knight Shortest Path

    http://www.lintcode.com/en/problem/knight-shortest-path/

    Given a knight in a chessboard (a binary matrix with 0 as empty and 1 as barrier) with a source position, find the shortest path to a destination position, return the length of the route. 
    Return -1 if knight can not reached.

    source and destination must be empty.
    Knight can not enter the barrier.

    notes:
*/


/**
 * Definition for a point.
 * struct Point {
 *     int x, y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /**
     * @param grid a chessboard included 0 (false) and 1 (true)
     * @param source, destination a point
     * @return the shortest path 
     */
    int shortestPath(vector<vector<bool>>& grid, Point& source, Point& destination) {
        
        // special case checks and setup
        if (grid.empty() || grid[0].empty()) { return 0; }
        int X = grid.size(), Y = grid[0].size();
        vector<Point> diffs = {{1,2}, {2,1},
                               {-1,-2}, {-2,-1},
                               {1,-2}, {2,-1},
                               {-1,2}, {-2,1}};
                               
        // state variables
        queue<pair<Point,int>> candidates;
        candidates.emplace(source,1);

        grid[source.x][source.y] = 1; // stepped already
        while (!candidates.empty()) {
            Point p = candidates.front().first;
            int n = candidates.front().second;
            for (auto diff : diffs) {
                int x = p.x + diff.x;
                int y = p.y + diff.y;
                if (x == destination.x && y == destination.y) { return n; }

                if (0 <= x && x < X && 0 <= y && y < Y && grid[x][y] == 0) {
                    grid[x][y] = 1;
                    candidates.emplace(Point(x,y), n+1);
                }
            }
            candidates.pop();
        }
        
        return -1;
    }
};

