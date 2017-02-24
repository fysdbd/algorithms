
/*
    Maximum Product Subarray

    description(leetcode:
                https://leetcode.com/problems/maximum-product-subarray/?tab=Description
                )

    Find the contiguous subarray within an array (containing at least one number) which has the largest product.

    For example, given the array [2,3,-2,4],
    the contiguous subarray [2,3] has the largest product = 6.


    notes:
    Probably not a great idea to try to discuss by cases of positive and negative as it could get tedious.
    Max and min is probably a neat solution
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) { return 0; }
        int curr_min = nums[0], curr_max = nums[0], result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int last_max = curr_max, last_min = curr_min;
            curr_max = std::max(std::max(last_max*nums[i], last_min*nums[i]), nums[i]);
            curr_min = std::min(std::min(last_max*nums[i], last_min*nums[i]), nums[i]);
            result = std::max(result, curr_max);
        }
        return result;
    }
};
