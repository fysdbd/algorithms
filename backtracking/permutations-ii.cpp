
/*
    Permutations II
    
    http://www.lintcode.com/en/problem/permutations-ii/
    
    Given a list of numbers with duplicate number in it. Find all unique permutations.

    Example
    For numbers [1,2,2] the unique permutations are:
    [
      [1,2,2],
      [2,1,2],
      [2,2,1]
    ]
    
    notes:
    slight difference from permutation i: duplicate prevention
    simply put a record of which item was last used; then do a comparison against it when selecting next

    diffenrences(few additional lines) has been makred for easy comparison
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    void traverse(vector<vector<int>>& results,
                  vector<int>& path,
                  vector<bool>& used,
                  vector<int>& nums){
        if (path.size() == nums.size()) { results.push_back(path); return; }
        
        long long last_used = std::numeric_limits<long long>::max();  // additional line
        for (int idx = 0; idx < nums.size(); idx++) {
            if (used[idx]) { continue; }
            if (nums[idx] == last_used) { continue; }                 // additional line
            
            path.push_back(nums[idx]);
            used[idx] = true;
            traverse(results, path, used, nums);
            path.pop_back();
            used[idx] = false;
            
            last_used = nums[idx];                                    // additional line
        }
    }
    
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        
        sort(nums.begin(), nums.end());                               // additional line
        
        vector<vector<int>> results;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        
        traverse(results, path, used, nums);
        return results;
    }
};
