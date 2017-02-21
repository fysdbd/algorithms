
/*
    LRU Cache

    description(leetcode:
                https://leetcode.com/problems/lru-cache/?tab=Description
                )

    Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
    get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
    put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity,
    it should invalidate the least recently used item before inserting a new item.

    Follow up:
    Could you do both operations in O(1) time complexity?

    Example:
    LRUCache cache = new LRUCache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);       // returns 1
    cache.put(3, 3);    // evicts key 2
    cache.get(2);       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    cache.get(1);       // returns -1 (not found)
    cache.get(3);       // returns 3
    cache.get(4);       // returns 4


    Relatively difficult solution to implement.
    One of key tricks to be bug free is to remove un-necessary data variables to keep;
    since that essentially all data variables (might) have to be maintained well at all functions/procedures.
    To be correct, one really needs to remember to update all state variables well in all functions,
    and how update should be handled at different cases.
*/


class LRUCache {
private:
    typedef struct node {
        int key;
        node* next;
        node(int k) : key(k) { next = nullptr; }
    } node_t;

    std::map<int,int> values;
    std::map<int, node*> prevs;
    int current_size = 0, cap;
    node* dummyhead{nullptr};
    node* tail{nullptr};

public:
    LRUCache(int capacity) {
        cap = capacity;
        dummyhead = tail = new node(0);
    }

    void moveTillEnd(node* prev) {
        if (prev->next == tail) { return; }

        tail->next = prev->next;
        prev->next = prev->next->next;
        tail->next->next = nullptr;
        prevs[tail->next->key] = tail;
        tail = tail->next;
        prevs[prev->next->key] = prev;
    }

    int get(int key) {

        if (values.find(key) == values.end()) { return -1; }
        moveTillEnd(prevs[key]);
        return values[key];
    }

    void evict() {

        current_size--;
        auto next = dummyhead->next->next;
        values.erase(values.find(dummyhead->next->key));
        prevs.erase(prevs.find(dummyhead->next->key));
        delete dummyhead->next;

        if (cap == 1) {
            tail = dummyhead;
        } else {
            prevs[next->key] = dummyhead;
            dummyhead->next = next;
        }
    }

    void put(int key, int value) {

        if (values.find(key) != values.end()) {
            values[key] = value;
            moveTillEnd(prevs[key]);
        } else {
            if (current_size == cap) { evict(); }
            tail->next = new node(key);
            prevs[key] = tail;
            tail = tail->next;
            current_size++;
            values[key] = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */




