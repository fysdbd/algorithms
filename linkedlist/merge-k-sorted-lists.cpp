
/*
    Merge k Sorted Lists

    description(leetcode
                https://leetcode.com/problems/merge-k-sorted-lists/
                )
    
    Merge k sorted linked lists and return it as one sorted list.
    Analyze and describe its complexity.
    
    notes:
    two obvious approaches: either merge 1 by 1 (as the following solution shows),
    or merge k lists at one time
    
    time complexity discussion:
    assuming k lists with longest list length being n, thus in total n*k
    merge 1 by 1:
        every comparison takes constant, thus every merge takes n*k
        with k lists, totally it is O(kkn)
    merge k lists as a whole:
        every comparison takes k, and need to do this operation for all elements
        thus totally it is O(kkn)
        however if comparison-complexity is improved by adopting some sorted data structure,
        the complexity can be reduced to
        O(kn logk)
        
    personally the first approach is easier programming-wise though
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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) { return nullptr; }
        
        std::queue<ListNode*> candidates;
        for (auto l : lists) { candidates.push(l); }
        while (candidates.size() > 1) {
            auto l1 = candidates.front(); candidates.pop();
            auto l2 = candidates.front(); candidates.pop();
            auto newlist = mergeTwoLists(l1,l2);
            candidates.push(newlist);
        }
        
        return candidates.front();
    }
};
