
/*
    Remove Duplicates from Sorted List

    Given a sorted linked list, delete all duplicates such that each element appear only once.

    For example,
    Given 1->1->2, return 1->2.
    Given 1->1->2->3->3, return 1->2->3.

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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->val == curr->next->val) {
                auto tmp = curr->next->next;
                delete curr->next;
                curr->next = tmp;
            } else {
                curr = curr->next;
            }
        }
        
        return head;
    }
};

