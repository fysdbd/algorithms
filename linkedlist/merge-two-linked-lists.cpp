
/*
    Merge Two Sorted Lists

    description(leetcode
                https://leetcode.com/problems/merge-two-sorted-lists/
                )

    Merge two sorted linked lists and return it as a new list.
    The new list should be made by splicing together the nodes of the first two lists.

    notes:
    a good linked list example problem that work well with dummy head node

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummyhead = new ListNode(0);
        ListNode* curr = dummyhead;
        while (l1 || l2) {
            auto & ptr =  ((l2 == nullptr || (l1 && l1->val < l2->val)) ? l1 : l2);
            curr = curr->next = ptr;
            ptr = ptr->next;
        }
        ListNode* head = dummyhead->next;
        delete dummyhead;
        return head;
    }
};
