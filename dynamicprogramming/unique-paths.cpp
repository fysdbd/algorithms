/*

    Unique Paths

    A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

    The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

    How many possible unique paths are there?

*/


class Solution {
public:
    int uniquePaths(int m, int n) {

        if (m*n == 0) { return 0; }
        vector<int> sum_matrix(m*n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum_matrix[i*n + j] = (i*j == 0 ? 1 : sum_matrix[i*n + j - 1] + sum_matrix[(i-1)*n + j]);
            }
        }

        return sum_matrix.back();
    }
};


