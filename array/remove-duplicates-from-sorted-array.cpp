
/*
	Remove Duplicates from Sorted Array

	description(leetcode
				https://leetcode.com/problems/remove-duplicates-from-sorted-array/?tab=Description
				)

	Given a sorted array, remove the duplicates in place such that each
	element appear only once and return the new length.

	Do not allocate extra space for another array,
	you must do this in place with constant memory.

	For example,
	Given input array nums = [1,1,2],

	Your function should return length = 2,
	with the first two elements of nums being 1 and 2 respectively.
	It doesn't matter what you leave beyond the new length.

*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        // state variables
        int back = 0, front = 0;
        set<int> collection;

        while (front < nums.size()) {
            if (collection.find(nums[front]) == collection.end()) {
                collection.insert(nums[front]);
                swap(nums[front++],nums[back++]);
            } else {
                front++;
            }
        }
        return back;   
    }
};
