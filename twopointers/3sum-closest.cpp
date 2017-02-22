
/*
    3Sum Closest

    description(leetcode:
                https://leetcode.com/problems/3sum-closest/?tab=Description
                )

    Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
    Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.
    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        int anchor = 0;
        int result;
        bool set = false;

        for (int anchor = 0; anchor < nums.size(); anchor++) {
            int left = anchor+1, right = nums.size()-1;
            while (left < right) {
                int val = nums[anchor]+nums[left]+nums[right];
                result = (!set || std::abs(val-target) < std::abs(result-target)) ? val : result;
                set = true;

                (val > target ? right-- : left++);
            }
        }

        return result;
    }
};
