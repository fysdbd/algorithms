
/*
    Reorder List

    description(leetcode:
                https://leetcode.com/problems/reorder-list/?tab=Description
                )

    Given a singly linked list L: L0→L1→…→Ln-1→Ln,
    reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

    You must do this in-place without altering the nodes' values.

    For example,
    Given {1,2,3,4}, reorder it to {1,4,2,3}.

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
    int getLength(ListNode* node) {
        int count = 0;
        while (node != nullptr) { count++; node = node->next; }
        return count;
    }

    ListNode* advance(ListNode* node, int n) {
        while(n--) { node = node->next; }
        return node;
    }

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

    ListNode* mergeOddEven(ListNode* l1, ListNode* l2) {

        ListNode* dummyhead = new ListNode(0);
        ListNode* curr = dummyhead;
        bool isOdd = true;
        while (l1 || l2) {
            auto & ptr =  ((l2 == nullptr || (l1 && isOdd)) ? l1 : l2);
            curr = curr->next = ptr;
            ptr = ptr->next;
            isOdd = !isOdd;
        }
        ListNode* head = dummyhead->next;
        delete dummyhead;
        return head;
    }

    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) { return; }

        auto mid_prev = advance(head, (getLength(head)-1)/2);
        ListNode* first = head;
        ListNode* second = reverse(mid_prev->next);
        mid_prev->next = nullptr;

        head = mergeOddEven(first, second);
    }
};
