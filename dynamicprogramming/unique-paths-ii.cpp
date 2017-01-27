
/*
    Unique Paths II


    Follow up for "Unique Paths":
    Now consider if some obstacles are added to the grids. How many unique paths would there be?
    An obstacle and empty space is marked as 1 and 0 respectively in the grid.
    For example,
    There is one obstacle in the middle of a 3x3 grid as illustrated below.

    [
      [0,0,0],
      [0,1,0],
      [0,0,0]
    ]
    The total number of unique paths is 2.

    Note: m and n will be at most 100.

*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) { return 0; }
        int m = obstacleGrid.size(), n = obstacleGrid.at(0).size();
        vector<int> sum_matrix(m*n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) { sum_matrix[0] = (obstacleGrid[0][0] == 0); continue; }
                auto left = (j == 0 ? 0 : sum_matrix[i*n + j - 1]);
                auto up = (i == 0 ? 0 : sum_matrix[(i-1)*n + j]);
                sum_matrix[i*n + j] = (obstacleGrid[i][j] ? 0 : left + up);
            }
        }

        return sum_matrix.back();
    }
};

