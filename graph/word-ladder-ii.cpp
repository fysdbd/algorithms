
/*
    Word Ladder II

    descriptin(lintcode
               https://www.lintcode.com/en/problem/word-ladder-ii/
               )

    Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:
    Only one letter can be changed at a time
    Each intermediate word must exist in the dictionary
    All words have the same length.
    All words contain only lowercase alphabetic characters.

    Example
    Given:
    start = "hit"
    end = "cog"
    dict = ["hot","dot","dog","lot","log"]
    Return
      [
        ["hit","hot","dot","dog","cog"],
        ["hit","hot","lot","log","cog"]
      ]

    notes:
    1. this is a pretty tough problem which requires quite some programming muscle to solve
       a solution to this problem could easily involve a number of different steps
       e.g. the solution displayed here split the problem into two parts, one bfs and dfs
    2. attempts were made to build neighbors between any pair of nodes; however such an operation
       easily run into "Time Limit Exceeds" in some OJs
    3. some checking may be added in cases that such path does not exist

*/

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return a list of lists of string
      */

    typedef struct wordinfo {
        bool found{false};          // indicator whether is node has been foud
        int steps{0};               // what is the smallest number of steps requried to be here
        vector<string> prevs;       // prev nodes
    } wordinfo_t;

    vector<string> getNeighbors(const unordered_set<string> &wordList, const string& str) {
        vector<string> neighbors;
        for (int i = 0; i < str.size(); i++) {
            string newstr = str;
            for (char c = 'a'; c <= 'z'; c++) {
                newstr[i] = c;
                if (c == str[i] || wordList.find(newstr) == wordList.end()) { continue; }
                neighbors.push_back(newstr);
            }
        }
        return neighbors;
    }

    void dfs(vector<vector<string>>& result,
             vector<string>&path,
             map<string, wordinfo>& wordinfos,
             const string& target) {
        auto laststr = path.back();
        if (laststr == target) { result.push_back(path); return; }
        for (auto neighbor : wordinfos[laststr].prevs) {
            path.push_back(neighbor);
            dfs(result, path, wordinfos, target);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        wordList.insert(beginWord);
        wordList.insert(endWord);

        // start bfs - following are state variables to maintain
        queue<string> q; q.push(beginWord);
        map<string, wordinfo> wordinfos;
        while (!q.empty()) {
            auto str = q.front(); q.pop();
            for (auto neighbor : getNeighbors(wordList, str)) {
                if (!wordinfos[neighbor].found) {
                    wordinfos[neighbor].found = true;
                    wordinfos[neighbor].steps = wordinfos[str].steps+1;
                    q.push(neighbor);
                }
                if (wordinfos[str].steps+1 <= wordinfos[neighbor].steps) {
                    wordinfos[neighbor].prevs.push_back(str);
                }
            }
        }

        // build all paths - this is going back to backtracking - dfs
        vector<vector<string>> result;
        vector<string> path = {endWord};
        dfs(result, path, wordinfos, beginWord);
        for (auto & vec : result) { reverse(vec.begin(), vec.end()); }
        return result;
    }
};

