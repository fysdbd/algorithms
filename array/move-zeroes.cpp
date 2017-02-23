
/*
    Move Zeroes

    description(leetcode:
                https://leetcode.com/problems/move-zeroes/?tab=Description
                )

    Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
    For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

    Note:
    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.

*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int curr = 0;
        for (int index = 0; index < nums.size(); index++) {
            if (nums.at(index) != 0) {
                swap(nums.at(curr++), nums.at(index));
            }
        }
    }
};

