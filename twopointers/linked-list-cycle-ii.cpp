
/*
    Linked List Cycle II


    Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

    Note: Do not modify the linked list.

    Follow up:
    Can you solve it without using extra space?
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

    ListNode *detectCycle(ListNode *head) {
        
        auto fast = head, slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) { break; }
        }
        if (fast == nullptr || fast->next == nullptr) { return nullptr; }
        
        fast = head;
        while (fast != slow) { fast = fast->next; slow = slow->next; }
        return fast;
    }
};

