
/*
    Reverse Linked List II

    Reverse a linked list from position m to n.
    Given m, n satisfy the following condition: 1 ≤ m ≤ n ≤ length of list.

    Example
    Given 1->2->3->4->5->NULL, m = 2 and n = 4, return 1->4->3->2->5->NULL.

    notes:
*/

/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
     
    ListNode* advance(ListNode* node, int n) {
        while(n--) { node = node->next; }
        return node;
    }
    
    ListNode* reverse(ListNode* node) {
        if (node == nullptr || node->next == nullptr) { return node; }
        ListNode* prev = node;
        ListNode* curr = node->next;
        prev->next = nullptr;
        while (curr != nullptr) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
    
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        
        ListNode* prev = advance(dummyhead, m-1);
        ListNode* to_reverse = prev->next;
        ListNode* next_prev = advance(to_reverse, n-m);
        ListNode* next = next_prev->next;
        next_prev->next = nullptr;
        
        ListNode* reversed = reverse(to_reverse);
        
        prev->next = reversed;
        to_reverse->next = next;
        
        head = dummyhead->next;
        delete dummyhead;
        return head;
    }
};



