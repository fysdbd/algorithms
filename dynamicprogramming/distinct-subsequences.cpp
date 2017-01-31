
/*
    Distinct Subsequences

    description(lintcode:
                http://www.lintcode.com/en/problem/distinct-subsequences/
                )

    Given a string S and a string T, count the number of distinct subsequences of T in S.
    A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
    Example
    Given S = "rabbbit", T = "rabbit", return 3.


    notes:
    m[r][c] means given first r+1 chars in T, can many subsequence can it find in first c+1 chars in S
    example:   
      r a b b b i t
    r 1 ? ?
    a   1 1
    b     1 2 3
    b       1 3
    i
    t

*/



class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    typedef std::vector<int> row;
    typedef std::vector<row> matrix;
    int numDistinct(string &S, string &T) {

        if (T.empty()) { return 1; }
        if (T.size() > S.size()) { return 0; }
        
        int R = T.size(), C = S.size();
        matrix m(R, row(C, 0));
        
        m[0][0] = S[0] == T[0];
        for (int c = 0; c < C; c++) {
            m[0][c] = m[0][c-1] + (T[0] == S[c] ? 1 : 0);
        }
        
        for (int r = 1; r < R; r++) {
            for (int c = r; c < C; c++) {
                m[r][c] = m[r-1][c-1] + (T[r] == S[c] ? m[r][c-1] : 0);
            }
        }
        
        return m[R-1][C-1];
    }
};

