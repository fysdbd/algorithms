
/*
    Maximum Subarray

    description(leetcode:
                https://leetcode.com/problems/maximum-subarray/
                )

    Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

    For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
    the contiguous subarray [4,-1,2,1] has the largest sum = 6.

    notes:
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_best_acc = 0;
        int curr_max = *(max_element(nums.begin(), nums.end()));
        for (auto num : nums) {
            curr_best_acc += num;
            curr_max = std::max(curr_max, curr_best_acc);
            if (num < 0 && curr_best_acc < 0) { curr_best_acc = 0; }
        }
        return curr_max;        
    }
};

