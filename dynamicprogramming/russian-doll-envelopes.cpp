
/*
    Russian Doll Envelopes

    description(leetcode
                https://leetcode.com/problems/russian-doll-envelopes/
                )
                
    You have a number of envelopes with widths and heights given as a pair of integers (w, h).
    One envelope can fit into another if and only if both the width and
    height of one envelope is greater than the width and height of the other envelope.

    What is the maximum number of envelopes can you Russian doll? (put one inside other)

    Example:
    Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

    
    notes:
    extension from Longest Increasing Subsequence problem
*/

class Solution {
public:
    bool smaller(const pair<int, int>& p1, const pair<int, int>& p2) {
        if (p1.first == p2.first) { return p1.second > p2.second; }
        else { return p1.first < p2.first; }
    }

    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        using namespace std::placeholders;
        sort(envelopes.begin(), envelopes.end(), std::bind(&Solution::smaller, this, _1, _2));
        
        set<int> record;
        for (int i = 0; i < envelopes.size(); i++) {
            auto it = lower_bound(record.begin(), record.end(), envelopes[i].second);
            if (it != record.end()) { record.erase(it); }
            record.insert(envelopes[i].second);
        }
        
        return record.size();
    }
};
