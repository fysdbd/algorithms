
/*
    Maximal Square

    description(leetcode:
                https://leetcode.com/problems/maximal-square/
                )

    Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

    For example, given the following matrix:

    1 0 1 0 0
    1 0 1 1 1
    1 1 1 1 1
    1 0 0 1 0
    Return 4.


    notes:
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        if (matrix.empty() || matrix[0].empty()) { return 0; }
        
        int R = matrix.size(), C = matrix.at(0).size();
        vector<vector<int>> sol_matrix(R, vector<int>(C, 0));
        
        int longest = 0;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (matrix[r][c] != '1') { continue; }
                
                int up = (r != 0 ? sol_matrix.at(r-1).at(c) : 0);
                int left = (c != 0 ? sol_matrix.at(r).at(c-1) : 0);

                sol_matrix[r][c] = std::min(up, left) + (up != left || matrix.at(r-up).at(c-left) == '1');
                longest = std::max(longest, sol_matrix[r][c]);
            }
        }
        return longest*longest;  
    }
};


