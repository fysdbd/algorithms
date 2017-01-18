
/*******************************************************************************

  Search For A Range

  description(from leetcode
              https://leetcode.com/problems/search-for-a-range/
              )

  Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
  Your algorithm's runtime complexity must be in the order of O(log n).
  If the target is not found in the array, return [-1, -1].
  For example,
      Given [5, 7, 7, 8, 8, 10] and target value 8,
      return [3, 4].

  comments:
  extension from most straightforward classical binary search

  the whole problem decompose into few steps: first locate at least one target element
  and then based on the index, locate the left bound and right bound

*******************************************************************************/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> not_found = {-1, -1};
        vector<int> found_range = {-1, -1};
        if (nums.empty()) { return not_found; }
        
        // first try to locate at least one target element
        int left = 0, right = nums.size()-1, idx;
        bool found = false;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                idx = mid;
                found = true;
                break;
            }
            (target > nums[mid] ? left : right) = mid;
        }
        
        // check if at least one target element found
        if (!found){
            if (nums[left] == target) { idx = left; }
            else if (nums[right] == target) { idx = right; }
            else { return not_found; }            
        }

        // locate left bound
        left = 0; right = idx;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            (nums[mid] == target ? right : left) = mid;
        }
        found_range[0] = ((nums[left] == target) ? left : right);
        
        // locate right bound
        left = idx; right = nums.size()-1;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            (nums[mid] == target ? left : right) = mid;
        }
        found_range[1] = ((nums[right] == target) ? right : left);
        
        return found_range;
    }
};
