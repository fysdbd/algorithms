
/*
    Distinct Subsequences

    description(leetcode:
                https://leetcode.com/problems/distinct-subsequences/
                )


    Given a string S and a string T, count the number of distinct subsequences of T in S.

    A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

    Here is an example:
    S = "rabbbit", T = "rabbit"
    Return 3.

    notes:
*/

class Solution {
public:
    int numDistinct(string s, string t) 
    {
        int R = s.size() + 1, C = t.size() + 1;
        vector<vector<int>> notes(R, vector<int>(C, 0));
        
        for (int c = 1; c < C; c++) { notes.at(0).at(c) = 1; }
        for (int r = 1; r < R; r++) {
            for (int c = 1; c < C; c++) {
                notes.at(r).at(c) = (s.at(r-1) == t.at(c-1)) * notes.at(r-1).at(c-1) + notes.at(r-1).at(c);
            }
        }
        
        return notes.at(R-1).at(C-1);
    }
};

