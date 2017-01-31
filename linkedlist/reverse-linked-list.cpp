

/*
    Reverse Linked List

    description(lintcode
                http://www.lintcode.com/en/problem/reverse-linked-list/

    Reverse a linked list.

    Example
    For linked list 1->2->3, the reversed linked list is 3->2->1

*/

/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        
        ListNode* prev =  nullptr;
        while (head != nullptr) {
            ListNode* tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }
};


