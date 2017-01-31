
/*
    Minimum Path Sum

    description(lintcode:
                http://www.lintcode.com/en/problem/minimum-path-sum/
                )

    Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

    You can only move either down or right at any point in time.

    notes:
*/

class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    typedef vector<int> row;
    typedef vector<row> matirx;
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty() || grid[0].empty()) { return 0; }
        
        int R = grid.size(), C = grid[0].size();
        for (int r = 1; r < R; r++) { grid[r][0] += grid[r-1][0]; }
        for (int c = 1; c < C; c++) { grid[0][c] += grid[0][c-1]; }
        
        for (int r = 1; r < R; r++) {
            for (int c = 1; c < C; c++) {
                grid[r][c] += std::min(grid[r-1][c], grid[r][c-1]);
            }
        }
        
        return grid[R-1][C-1];
    }
};


