
/*******************************************************************************
  Search in Rotated Sorted Array II

  description:(leetcode
               https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
               )

  Follow up for "Search in Rotated Sorted Array":
  What if duplicates are allowed?
  Would this affect the run-time complexity? How and why?
  Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
  (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
  Write a function to determine if a given target is in the array.
  The array may contain duplicates.

  comments:

  it gets more complicated than search-in-rotated-sorted-array-ii, since we cannot always know things for sure
  when edge numbers are the same since there can be duplicates

  there are more than one approach to the problem for sure.
  personally finding following one more clear:

  instead of trying to dicuss multiple different cases on relationsip between left, mid, right
  one can use a bit "exclusion thinking"
  as in binary search problems, the algorithm is usually expected to choose, or exclude a side
  e.g. in this case, instead of trying to figure out when will target stay in [mid, right],
  one can more easily identify the condition in which it will NOT be in [left, mid]

  additionally, there may be cases in which we can exclude neither side, e.g A[left] = A[mid] = A[right]
  in this case binary split can hardly help here, thus we can only iterate slowly by checking linearly
  apparently this brings worst case time complexity to O(n)
  but imagine a huge array with all same elements equal 1, except a zero somewhere in the array.
  nothing can be done to help accelerate the search process, since it really can be anywhere
  thus the worse case time complexity can be somewhat justified

*******************************************************************************/


class Solution {
    /**
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean
     */
public:
    bool search(vector<int> &A, int target) {

        if (A.empty()) { return false; }

        int left = 0, right = A.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] == target || A[left] == target || A[right] == target) { return true; }

            if (A[mid] > A[left] && (target < A[left] || target > A[mid]) ) {
                // in what cases, can we be sure that it is not in left half?
                left = mid;
            } else if (A[mid] < A[right] && (target > A[right] || target < A[mid]) ) {
                // in what cases, can be be sure that it is not in right half?
                right = mid;
            } else {
                // well if neither is case, we cannot judge which side at all. lets move slow
                left++;
                right--;
            }
        }

        return A[left] == target || A[right] == target;
    }
};
