
/*
    Add Two Numbers II

    description(leetcode:
                https://leetcode.com/problems/add-two-numbers-ii/?tab=Description
                )

    You are given two non-empty linked lists representing two non-negative integers.
    The most significant digit comes first and each of their nodes contain a single digit.
    Add the two numbers and return it as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.
    Follow up:
    What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

    Example:
    Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 8 -> 0 -> 7


    notes:
    The addTwoNumbersReversed function was directly taken from add-two-numbers(i)
    The reverse function is more common; found in many linked list problems
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

    ListNode* addTwoNumbersReversed(ListNode* l1, ListNode* l2) {

        ListNode* dummyhead = new ListNode(0);
        ListNode* curr = dummyhead;
        bool hasAdditionalOne = false;

        while (l1 != nullptr || l2 != nullptr) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + (hasAdditionalOne ? 1 : 0);
            hasAdditionalOne = sum / 10;
            curr = curr->next = new ListNode(sum % 10);

            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        if (hasAdditionalOne) { curr->next = new ListNode(1); }

        auto head = dummyhead->next;
        delete dummyhead;
        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return reverse(addTwoNumbersReversed(reverse(l1), reverse(l2)));
    }
};
