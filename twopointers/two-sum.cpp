
/*
    Two Sum

    description(leetcode:
                https://leetcode.com/problems/two-sum/
                )

    Given an array of integers, return indices of the two numbers such that they add up to a specific target.
    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    Example:
    Given nums = [2, 7, 11, 15], target = 9,

    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].

    notes
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        std::unordered_map<int,int> rec;
        
        for (int idx = 0; idx < nums.size(); idx++) {
            int needed = target - nums[idx];
            if (rec.find(needed) != rec.end()) {
                return {rec[needed], idx};
            } else {
                rec.insert(std::make_pair(nums[idx], idx));
            }
        }
        
        return {-1,-1};
    }
};

