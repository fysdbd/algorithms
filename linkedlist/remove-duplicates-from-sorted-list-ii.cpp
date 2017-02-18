
/*
    Remove Duplicates from Sorted List II

    description(leetcode:
                https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/?tab=Description
                )

    Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
    For example,
    Given 1->2->3->3->4->4->5, return 1->2->5.
    Given 1->1->1->2->3, return 2->3.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeVal(ListNode* node, int val) {
        while (node->next != nullptr && node->next->val == val) {
            ListNode* tmp = node->next->next;
            delete node->next;
            node->next = tmp;
        }
        return node;
    }

    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* dummyhead = new ListNode(0);
        ListNode* curr = dummyhead;
        dummyhead->next = head;
        while (curr->next != nullptr) {
            if (curr->next->next != nullptr && curr->next->val == curr->next->next->val) {
                curr = removeVal(curr, curr->next->val);
            } else {
                curr = curr->next;
            }
        }

        head = dummyhead->next;
        delete dummyhead;
        return head;
    }
};
