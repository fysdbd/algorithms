
/*
    Palindrome Partitioning
    
    http://www.lintcode.com/en/problem/palindrome-partitioning/
    
    Given a string s, partition s such that every substring of the partition is a palindrome.
    Return all possible palindrome partitioning of s.

    Example
    Given s = "aab", return:

    [
      ["aa","b"],
      ["a","a","b"]
    ]
    
    notes:
*/

class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {

        vector<vector<string>> results;
        vector<string> path;
        traverse(s, results, 0, path);
        return results;
    }
    
    bool isPalindrome(string& str, int start, int end) {
        while (start < end) {
            if (str[start++] != str[end--]) { return false; }
        }
        return true;
    }
    
    void traverse(string& str, vector<vector<string>>& results, int start, vector<string>& path) {
        if (start >= str.size()) { results.push_back(path); return; }
        
        for (int end = start; end < str.size(); end++) {
            if (isPalindrome(str, start, end)) {
                path.push_back(str.substr(start, end-start+1));
                traverse(str, results, end+1, path);
                path.pop_back();
            }
        }
    }
};