
/*
    Longest Increasing Subsequence
    
    description(leetcode:
                https://leetcode.com/problems/longest-increasing-subsequence/
                )

                
    Given an unsorted array of integers, find the length of longest increasing subsequence.

    For example,
    Given [10, 9, 2, 5, 3, 7, 101, 18],
    The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

    Your algorithm should run in O(n2) complexity.

    Follow up: Could you improve it to O(n log n) time complexity?
    
    
    notes:
    very classic dynamic programming problem
    the key to O(nlog) solution lies in the choice of intermediate states
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        set<int> record;
        for(int i=0; i<nums.size(); i++) {
            auto it = record.lower_bound(nums[i]);
            if (it != record.end()) { record.erase(it); }
            record.insert(nums[i]);
        }
        return record.size();

    }
};

