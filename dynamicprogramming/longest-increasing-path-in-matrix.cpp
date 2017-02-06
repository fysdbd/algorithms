
/*
    Longest Increasing Path in a Matrix

    descriptin(leetcode
               https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
               )

    Given an integer matrix, find the length of the longest increasing path.

    From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

    Example 1:

    nums = [
      [9,9,4],
      [6,6,8],
      [2,1,1]
    ]
    Return 4
    The longest increasing path is [1, 2, 6, 9].

    Example 2:

    nums = [
      [3,4,5],
      [3,2,6],
      [2,2,1]
    ]
    Return 4
    The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

*/


class Solution {
public:
    void update(vector<vector<int>>& marks,
                vector<vector<int>>& matrix,
                int r,
                int c,
                int R,
                int C,
                int& result)
    {
        int best = 0;
        int val = matrix[r][c];
        if (r-1 >= 0 && val != matrix[r-1][c]) { best = max(best, marks[r-1][c]); }
        if (r+1 < R && val != matrix[r+1][c]) { best = max(best, marks[r+1][c]); }
        if (c-1 >= 0 && val != matrix[r][c-1]) { best = max(best, marks[r][c-1]); }
        if (c+1 < C && val != matrix[r][c+1]) { best = max(best, marks[r][c+1]); }
        marks[r][c] = best+1;
        result = max(result, marks[r][c]);
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix.front().empty()) { return 0; }
        int R = matrix.size(), C = matrix.front().size();
        
        map<int, vector<pair<int, int>>> levels;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                levels[matrix[r][c]].emplace_back(r, c);
            }
        }
        
        int result = INT_MIN;
        vector<vector<int>> marks(R, vector<int>(C, 0));
        for (auto level : levels) {
            for (auto p : level.second) {
                update(marks, matrix, p.first, p.second, R, C, result);
            }
        }
        return result;
    }
};

