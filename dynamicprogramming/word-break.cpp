
/*
    Word Break

    description(leetcode:
                https://leetcode.com/problems/word-break/
                )

    Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

    For example, given
    s = "leetcode",
    dict = ["leet", "code"].

    Return true because "leetcode" can be segmented as "leet code".

*/

class Solution {
public:
    bool matchFound(const vector<string>& word_vec, string& s, int stop_index, int word_len) {
        if (stop_index+1 < word_len) { return false; } // boundary check
        string sub_str = s.substr(stop_index+1-word_len, word_len);
        return (find(word_vec.begin(), word_vec.end(), sub_str) != word_vec.end());
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> reachable(s.size());
        
        map<int, vector<string>> words;
        for (const string& str : wordDict)  {
            if (words.find(str.size()) == words.end()) {
                vector<string> vec; vec.push_back(str);
                words.insert(make_pair(str.size(), vec));
            }
            else {
                words.at(str.size()).push_back(str);
            }
        }

        for (int stop_index = 0; stop_index < s.size(); stop_index++) {
            for (auto map_ptr : words) { // pick an ptr, gets a length and word_vec
                int word_len = map_ptr.first;
                const vector<string>& word_vec = map_ptr.second;
                
                if (matchFound(word_vec, s, stop_index, word_len)) {
                    if (stop_index+1 == word_len || (stop_index+1 > word_len && reachable.at(stop_index - word_len)) ) { 
                        reachable.at(stop_index) = true;
                    }
                }
            }
        }
        return reachable.back();
    }
};


