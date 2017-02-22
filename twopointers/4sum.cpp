
/*
    4Sum

    description(leetcode
                https://leetcode.com/problems/4sum/?tab=Description
                )

    Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
    Find all unique quadruplets in the array which gives the sum of target.

    Note: The solution set must not contain duplicate quadruplets.
    For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

    A solution set is:
    [
      [-1,  0, 0, 1],
      [-2, -1, 1, 2],
      [-2,  0, 0, 2]
    ]

*/


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int anchor1 = 0; anchor1 < nums.size(); anchor1++) {
            if (anchor1 != 0 && nums[anchor1] == nums[anchor1-1]) { continue; }                        // skip
            for (int anchor2 = anchor1+1; anchor2 < nums.size(); anchor2++) {
                if (anchor2 != anchor1+1 && nums[anchor2] == nums[anchor2-1]) { continue; }            // skip

                int left = anchor2+1, right = nums.size()-1;
                while (left < right) {
                    int val = nums[anchor1]+nums[anchor2]+nums[left]+nums[right];
                    if (val == target) {
                        result.push_back({nums[anchor1],nums[anchor2],nums[left],nums[right]});
                        int left_val = nums[left]; while (nums[left] == left_val) { left++; }
                        int right_val = nums[right]; while (nums[right] == right_val) { right--; }
                    } else {
                        (val > target ? right-- : left++);
                    }
                }
            }
        }
        return result;
    }
};
