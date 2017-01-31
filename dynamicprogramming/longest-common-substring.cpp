
/*
    Longest Common Substring

    Given two strings, find the longest common substring.
    Return the length of it.
    The characters in substring should occur continuously in original string. This is different with subsequence.

    Example
    Given A = "ABCD", B = "CBCE", return 2.

    notes:
    typical 2D matrix solution in dynamic programming problem:
    matrix[r][c] records the lenght of longest common substring that ends in index r and c respectively
*/

class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    typedef vector<int> row;
    typedef vector<row> matrix;
    int longestCommonSubstring(string &A, string &B) {

        if (A.empty() || B.empty()) { return 0; }
        
        int R = A.size(), C = B.size();
        matrix m(R, row(C, 0));
        
        int best = 0;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (A[r] != B[c]) { continue; }
                m[r][c] = ((r == 0 || c == 0) ? 1 : m[r-1][c-1]+1);
                best = std::max(best, m[r][c]);
            }
        }
        
        return best;
    }
};
