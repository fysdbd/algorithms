
/*
    Minimum Path Sum

    description(leetcode
                https://leetcode.com/problems/minimum-path-sum/
                )

    Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

    Note: You can only move either down or right at any point in time.


    notes:
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        if (grid.empty() || grid[0].empty()) { return 0; }
        int m = grid.size(), n = grid.at(0).size();
        vector<int> sum_matrix(m*n);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) { sum_matrix[0] = grid[0][0]; continue; }
                auto left = (j == 0 ? INT_MAX : sum_matrix[i*n + j - 1]);
                auto up = (i == 0 ? INT_MAX : sum_matrix[(i-1)*n + j]);
                sum_matrix[i*n + j] = std::min(left, up) + grid[i][j];
            }
        }

        return sum_matrix.back();
    }
};

