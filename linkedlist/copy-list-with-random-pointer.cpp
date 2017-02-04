
/*
    Copy List with Random Pointer
    
    description(leetcode
                https://leetcode.com/problems/copy-list-with-random-pointer/
                )

    A linked list is given such that each node contains an additional random pointer
    which could point to any node in the list or null.
    Return a deep copy of the list.

*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        
        if (head == nullptr) { return nullptr; }
        std::map<RandomListNode*, RandomListNode*> addrToNewAddr;
        RandomListNode* dummyhead = new RandomListNode(head->label);
        auto copycurr = dummyhead, curr = head;
        
        // round1 : straight copy
        while (curr != nullptr) {
            copycurr->next = new RandomListNode(curr->label);
            addrToNewAddr.insert(std::make_pair(curr, copycurr->next));

            curr = curr->next;
            copycurr = copycurr->next;
        }
        
        // round2 : random ptrs
        copycurr = dummyhead->next, curr = head;
        while (curr != nullptr) {
            copycurr->random = addrToNewAddr[curr->random];

            curr = curr->next;
            copycurr = copycurr->next;
        }
        
        copycurr = dummyhead->next;
        delete dummyhead;
        return copycurr;
    }
};
