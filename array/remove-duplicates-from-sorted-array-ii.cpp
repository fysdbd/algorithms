
/*
	Remove Duplicates from Sorted Array II
	
	description(leetcode
				https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/?tab=Description
				)

	Follow up for "Remove Duplicates":
	What if duplicates are allowed at most twice?

	For example,
	Given sorted array nums = [1,1,1,2,2,3],

	Your function should return length = 5,
	with the first five elements of nums being 1, 1, 2, 2 and 3.
	It doesn't matter what you leave beyond the new length.

*/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // state variables
        int back = 0, front = 0;
        map<int,int> collection;

        while (front < nums.size()) {
            if (collection[nums[front]]++ < 2) {
                swap(nums[front++],nums[back++]);
            } else {
                front++;
            }
        }
        return back;   
    }
};
