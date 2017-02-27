
/*
    Convert Sorted List to Binary Search Tree

    description(leetcode
                https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/?tab=Description
                )

    Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* convert(vector<int>& nums, int start, int end) {

        if (start > end) { return nullptr; }
        if (start == end) { return new TreeNode(nums[start]); }

        int index = (start + end + 1) / 2;
        TreeNode* node = new TreeNode(nums[index]);
        node->left = convert(nums, start, index-1);
        node->right = convert(nums, index+1, end);
        return node;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while (head != nullptr) {
            nums.push_back(head->val);
            head = head->next;
        }

        return convert(nums, 0, nums.size()-1);
    }
};
