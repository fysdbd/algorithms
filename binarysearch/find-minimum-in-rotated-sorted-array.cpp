
/*******************************************************************************

  Find Minimum In Rotated Sorted Array

  description(from leetcode
              https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
              ):

  Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
  (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
  Find the minimum element.
  You may assume no duplicate exists in the array.

  notes:

  just watch for all sorted (special) case in rotated sorted array problems

*******************************************************************************/


class Solution {
public:
    int findMin(vector<int>& nums) {

        int left = 0, right = nums.size()-1;
        if (nums[left] <= nums[right]) { return nums[left]; }

        while (left + 1 < right) {
            int mid = (left + right) / 2;
            (nums[mid] > nums[left] ? left : right) = mid;
        }

        return std::min(nums[left], nums[right]);
    }
};
