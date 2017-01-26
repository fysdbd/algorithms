
/*
    Permutations

    http://www.lintcode.com/en/problem/permutations/

    Given a list of numbers, return all possible permutations.
    You can assume that there is no duplicate numbers in the list.
    
    notes: backtrack by selecting next item in the permutation one by one
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    void traverse(vector<vector<int>>& results,
                  vector<int>& path,
                  vector<bool>& used,
                  vector<int>& nums){
        if (path.size() == nums.size()) { results.push_back(path); return; }
        
        for (int idx = 0; idx < nums.size(); idx++) {
            if (used[idx]) { continue; }
            
            path.push_back(nums[idx]);
            used[idx] = true;

            traverse(results, path, used, nums);

            path.pop_back();
            used[idx] = false;
        }
    }
    
    vector<vector<int>> permute(vector<int> nums) {
        
        vector<vector<int>> results;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        
        traverse(results, path, used, nums);
        return results;
    }
};
