
/*
    Linked List Cycle

    description(leetcode
                https://leetcode.com/problems/linked-list-cycle/
                )


    Given a linked list, determine if it has a cycle in it.

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
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;
        if (head->next == head) return true;
        
        auto fast = head->next, slow = head;
        while (fast != slow)
        {
            if (fast == nullptr || fast->next == nullptr) { return false; }
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};

