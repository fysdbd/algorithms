
/*
    Kth Largest Element in an Array

    Find the kth largest element in an unsorted array.
    Note that it is the kth largest element in the sorted order, not the kth distinct element.
    For example,
    Given [3,2,1,5,6,4] and k = 2, return 5.
    Note:
    You may assume k is always valid, 1 ≤ k ≤ array's length.

    notes:
    This problem is very similar to quicksort.
    Being familiar with some quicksort implementation is critical in an effective solution to this problem.
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return helper(nums, 0, nums.size()-1, k);
    }

    int helper(vector<int>& nums,
               int start,
               int end,
               int k) {
        int pivot = nums[start];

        // sort based on pivot
        int left = start+1, right = end;
        while (left <= right) {
            if (nums[left] < pivot) {
                swap(nums[left], nums[left-1]);
                left++;
            } else { // nums[right] > pivot
                swap(nums[left], nums[right]);
                right--;
            }
        }

        // deciding if we need to further the search, or just return
        int ranking = end-left+2;
        if (ranking == k) { return pivot; } // located
        else if (ranking > k) {
            return helper(nums, left, end, k);
        } else { // (ranking < k)
            return helper(nums, start, left-2, k-ranking);
        }
    }
};
