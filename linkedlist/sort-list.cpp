
/*
    Sort List

    Sort a linked list in O(n log n) time using constant space complexity.


    notes:
    The merge function, mergeTwoLists(ListNode*, ListNode*),
    is directly taken from the merge-two-lists problem
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

    ListNode* sortList(ListNode* head) {

        // base case
        if (head == nullptr || head->next == nullptr) { return head; }

        // find middle point
        auto fast = head->next, slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // sort and merge recursively
        auto l1 = head, l2 = slow->next;
        slow->next = nullptr;
        return mergeTwoLists(sortList(l1), sortList(l2));
    }
};

