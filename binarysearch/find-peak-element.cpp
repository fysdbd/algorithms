
/*******************************************************************************
    Find Peak Element

    description:(leetcode
                https://leetcode.com/problems/find-peak-element/
                )

    A peak element is an element that is greater than its neighbors.
    Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
    The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
    You may imagine that num[-1] = num[n] = -∞.
    For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

    notes:
    a bit deviation from basic binary search: how to determine the existence in a range based on edge number comparison

*******************************************************************************/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (isPeak(nums, mid)) { return mid; }
            (nums[mid-1] > nums[mid] ? right : left) = mid;
        }

        if (isPeak(nums, left)) { return left; }
        if (isPeak(nums, right)) { return right; }
        return -1;
    }

    bool isPeak(vector<int>& nums, int idx) {
        if (idx == 0)               { return nums.size() == 1 || nums[idx] > nums[idx+1]; }
        if (idx == nums.size()-1)   { return nums.size() == 1 || nums[idx] > nums[idx-1]; }
        return (nums[idx] > nums[idx-1] && nums[idx] > nums[idx+1]);
    }
};
