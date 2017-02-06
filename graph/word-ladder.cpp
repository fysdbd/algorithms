
/*
    Word Ladder

    description(lintcode
                https://www.lintcode.com/en/problem/word-ladder/#
                )

    Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:
    Only one letter can be changed at a time
    Each intermediate word must exist in the dictionary
    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.

    Example
    Given:
    start = "hit"
    end = "cog"
    dict = ["hot","dot","dog","lot","log"]
    As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
    return its length 5.

*/

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */

    vector<string> getNeighbors(const unordered_set<string> &dict, const string& str) {
        vector<string> neighbors;
        for (int i = 0; i < str.size(); i++) {
            string newstr = str;
            for (char c = 'a'; c <= 'z'; c++) {
                newstr[i] = c;
                if (c == str[i] || dict.find(newstr) == dict.end()) { continue; }
                neighbors.push_back(newstr);
            }
        }
        return neighbors;
    }

    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end) { return 1; }

        dict.insert(start);
        dict.insert(end);

        queue<string> q; q.push(start);
        map<string, int> wordDistance; wordDistance.emplace(start, 1);
        while (!q.empty()) {
            auto str = q.front(); q.pop();
            for (auto neighbor : getNeighbors(dict, str)) {
                if (neighbor == end) { return wordDistance[str]+1; }
                if (wordDistance.find(neighbor) == wordDistance.end()) {
                    wordDistance[neighbor] = INT_MAX;
                    q.push(neighbor);
                }
                wordDistance[neighbor] = std::min(wordDistance[neighbor], wordDistance[str]+1);
            }
        }

        return 0;
    }
};

