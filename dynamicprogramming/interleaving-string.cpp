
/*
    Interleaving String

    description(lintcode
                http://www.lintcode.com/en/problem/interleaving-string/
                )

    Given three strings: s1, s2, s3, determine whether s3 is formed by the interleaving of s1 and s2.
    Example
    For s1 = "aabcc", s2 = "dbbca"
    When s3 = "aadbbcbcac", return true.
    When s3 = "aadbbbaccc", return false.

    notes:
    here, the boolean value of matrix[r][c] means:
    in here we prepare an additional layer
    is substring s1[0 to r] with s2[0 to c] forms s3[0 to r+c-1]
*/

class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    typedef std::vector<bool> row;
    typedef std::vector<row> matrix;
    bool isInterleave(string s1, string s2, string s3) {

        // some sanity check to handle special cases
        if (s1.size() + s2.size() != s3.size()) { return false; }
        if (s1.empty()) { return s2 == s3; }
        if (s2.empty()) { return s1 == s3; }

        int R = s1.size(), C = s2.size();
        matrix m(R+1, row(C+1, true));

        for (int r = 1; r <= R; r++) {
            m[r][0] = (s1[r-1] == s3[r-1] && m[r-1][0]);
        }

        for (int c = 1; c <= C; c++) {
            m[0][c] = (s2[c-1] == s3[c-1] && m[0][c-1]);
        }

        for (int r = 1; r <= R; r++) {
            for (int c = 1; c <= C; c++) {
                m[r][c] = ( (s1[r-1] == s3[r+c-1] && m[r-1][c]) ||
                            (s2[c-1] == s3[r+c-1] && m[r][c-1])  );
            }
        }
        return m[R][C];
    }
};

