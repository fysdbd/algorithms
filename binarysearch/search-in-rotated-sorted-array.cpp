
/*******************************************************************************
  Search in Rotated Sorted Array

  description:(leetcode:
               https://leetcode.com/problems/search-in-rotated-sorted-array/
               )

  Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
  (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
  You are given a target value to search. If found in the array return its index, otherwise return -1.
  You may assume no duplicate exists in the array.

  notes:

  classic problem.
  need to discuss cases upon whether the array is "truly rotated" or actually in order

*******************************************************************************/

class Solution {
public:
    int search(vector<int>& nums, int target) {

        if (nums.empty()) { return -1; }
        int left = 0, right = nums.size()-1;

        if (nums[0] >= nums.back()) {
            while (left + 1 < right) {
                int mid = (left + right) / 2;
                // question: in which cases will we use left half side for next loop?
                bool use_left = (nums[left] < nums[mid] && nums[left] <= target && target <= nums[mid])
                                    || (nums[mid] < nums[right] && target > nums[right])
                                    || (nums[mid] < nums[right] && target < nums[mid]) ;
                (use_left ? right : left) = mid;
            }
        } else {
            while (left + 1 < right) {
                int mid = (left + right) / 2;
                if (nums[mid] == target) { return mid; }
                (nums[mid] > target ? right : left) = mid;
            }
        }

        if (nums[left] == target) { return left; }
        if (nums[right] == target) { return right; }
        return -1;
    }
};

