
/*
    Word Break II

    description(leetcode
                https://leetcode.com/problems/word-break-ii/
                )

    Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.

    Return all such possible sentences.

    For example, given
    s = "catsanddog",
    dict = ["cat", "cats", "and", "sand", "dog"].

    A solution is ["cats and dog", "cat sand dog"].

*/

class Solution {
public:
    bool matchFound(const vector<string>& word_vec, string& s, int stop_index, int word_len) {
        if (stop_index+1 < word_len) return false; // boundary check
        string sub_str = s.substr(stop_index+1-word_len, word_len);
        return (find(word_vec.begin(), word_vec.end(), sub_str) != word_vec.end());
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<string>> sol(s.size()); 
        vector<bool> reachable(s.size());
        
        map<int, vector<string>> words;
        for (const string& str : wordDict) {
            if (words.find(str.size()) == words.end()) {
                vector<string> vec; vec.push_back(str);
                words.insert(make_pair(str.size(), vec));
            }
            else {
                words.at(str.size()).push_back(str);
            }
        }

        // screening phase
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
        if (reachable.back() == false) return sol.back();
        
        // solution generation
        for (int stop_index = 0; stop_index < s.size(); stop_index++) {
            for (auto map_ptr : words) { // pick an ptr, gets a length and word_vec
                int word_len = map_ptr.first;
                const vector<string>& word_vec = map_ptr.second;
                
                if (matchFound(word_vec, s, stop_index, word_len))  {
                    string sub_str = s.substr(stop_index+1-word_len, word_len);
                    if (stop_index+1 == word_len) sol.at(stop_index).push_back(sub_str); 
                    else if (stop_index+1 > word_len) {
                        for (string str : sol.at(stop_index - word_len)) {
                            str += " ";
                            str += sub_str;
                            sol.at(stop_index).push_back(str);
                        }                        
                    }
                }
            }
        }
        
        return sol.back();
    }
};


