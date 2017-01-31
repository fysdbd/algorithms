
/*
    3Sum

    Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

    Note: The solution set must not contain duplicate triplets.

    For example, given array S = [-1, 0, 1, 2, -1, -4],
    A solution set is:
    [
      [-1, 0, 1],
      [-1, -1, 2]
    ]

    notes
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty()) { return result; }
        
        sort(nums.begin(), nums.end());
        for (int anchor = 0; anchor < nums.size()-1; anchor++) {
            // important skip
            if (anchor > 0 && nums[anchor] == nums[anchor-1]) { continue; }
            
            int anchor_val = nums[anchor];
            int start = anchor+1, end = nums.size()-1;
            while (start < end) {
                int small = nums[start], big = nums[end];
                int sum = anchor_val + small + big;
                if (sum == 0) {
                    result.push_back({anchor_val, small, big});
                    while (start < end && nums[start] == small) { ++start; }
                    while (start < end && nums[end] == big) { --end; }
                } else if (sum > 0) {
                    end--;
                } else { // sum < 0
                    start++;
                }
            }
        }
        
        return result;   
    }
};

