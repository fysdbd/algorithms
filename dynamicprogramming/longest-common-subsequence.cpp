
/*
    Longest Common Subsequence

    Given two strings, find the longest common subsequence (LCS).
    Your code should return the length of LCS.

    Clarification
    What's the definition of Longest Common Subsequence?

    https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
    http://baike.baidu.com/view/2020307.htm
    Example
    For "ABCD" and "EDCA", the LCS is "A" (or "D", "C"), return 1.
    For "ABCD" and "EACB", the LCS is "AC", return 2.

    notes:
    the key efficiency of dynamic programming alogrithm lies in the choice of state variable chosen
    here in this problem, matrix[r][c] means the solution for A, B ending at r and c
    NOT using character at r and c as the last index
*/


class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    typedef std::vector<int> row;
    typedef std::vector<row> matrix;
    int longestCommonSubsequence(string A, string B) {
        
        if (A.empty() || B.empty()) { return 0; }
        int R = A.size(), C = B.size();
        matrix m(R, row(C, 0));
        
        m[0][0] =  (A[0] == B[0]);
        
        for (int r = 1; r < R; r++) {
            m[r][0] = (m[r-1][0] || A[r] == B[0]);
        }
        
        for (int c = 1; c < C; c++) {
            m[0][c] = (m[0][c-1] || A[0] == B[c]);
        }
        
        for (int r = 1; r < R; r++) {
            for (int c = 1; c < C; c++) {
                m[r][c] = ( (A[r] == B[c]) ? m[r-1][c-1]+1 : std::max(m[r][c-1],m[r-1][c]) );
            }
        }
        
        return m[R-1][C-1];
    }
};
