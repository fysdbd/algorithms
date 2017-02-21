
/*
	LFU Cache

	descriptoion(leetcode
				 https://leetcode.com/problems/lfu-cache/?tab=Description
				 )

	Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.

	get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
	put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

	Follow up:
	Could you do both operations in O(1) time complexity?

	Example:

	LFUCache cache = new LFUCache(2);

	cache.put(1, 1);
	cache.put(2, 2);
	cache.get(1);       // returns 1
	cache.put(3, 3);    // evicts key 2
	cache.get(2);       // returns -1 (not found)
	cache.get(3);       // returns 3.
	cache.put(4, 4);    // evicts key 1.
	cache.get(1);       // returns -1 (not found)
	cache.get(3);       // returns 3
	cache.get(4);       // returns 4

*/

class LFUCache {
private:
    typedef struct freq_level {
        int freq{};
        std::list<int> data;
        freq_level(int f) : freq(f) {}
    } freq_level_t;

    std::map<int,int> values;
    std::map<int,int> frequencies;
    std::deque<freq_level_t> freqs_structure;
    int cap, curr_size = 0;
public:
    LFUCache(int capacity) { cap = capacity; }

    void upgrade_freq(int key) {

        int freq = frequencies[key]++;
        auto it = freqs_structure.begin();
        while (it->freq != freq) { it++; }
        it->data.erase(find(it->data.begin(), it->data.end(), key));
        it = (it->data.empty() ? freqs_structure.erase(it) : it+1);

        if (it == freqs_structure.end() || it->freq != freq+1) {
            it = freqs_structure.insert(it, freq_level(freq+1));
        }
        it->data.push_back(key);
    }

    void insert(int key, int value) {

        if (freqs_structure.empty() || freqs_structure.front().freq != 0) {
            freqs_structure.emplace_front(freq_level(0));
        }
        freqs_structure.front().data.push_back(key);

        values[key] = value;
        frequencies[key] = 0;
        curr_size++;
    }

    void evict() {

        int removed_val = *(freqs_structure.front().data.begin());
        freqs_structure.front().data.pop_front();

        values.erase(values.find(removed_val));
        frequencies.erase(frequencies.find(removed_val));
        curr_size--;
    }

    int get(int key) {

        if (values.find(key) == values.end()) {
            return -1;
        } else {
            upgrade_freq(key);
            return values[key];
        }
    }

    void put(int key, int value) {

        if (cap == 0) { return; }

        if (values.find(key) != values.end()) {
            upgrade_freq(key);
            values[key] = value;
        } else {
            if (curr_size == cap) { evict(); }
            insert(key, value);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
 
