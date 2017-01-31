
/*
    Combination Sum II

    description(lintcode:
                http://www.lintcode.com/en/problem/combination-sum-ii/
                )
    
    Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
    Each number in C may only be used once in the combination.

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.
    Have you met this question in a real interview? Yes
    Example
    Given candidate set [10,1,6,7,2,1,5] and target 8,

    A solution set is:
    [
      [1,7],
      [1,2,5],
      [2,6],
      [1,1,6]
    ]
    
    notes:

*/

class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
	 
    void traverse(vector<vector<int>>& results,
                  vector<int>& candidates,
                  vector<int>& path,
                  int index, 
                  int acc,
                  int target){
                      
        if (acc == target) { results.push_back(path); return; }
        if (index >= candidates.size() || acc > target) { return; }
        
        for (int idx = index; idx < candidates.size(); idx++) {
            if (idx > index && candidates[idx] == candidates[idx-1]) { continue; }
            path.push_back(candidates[idx]);
            traverse(results,
                     candidates,
                     path,
                     idx+1,
                     acc + candidates[idx],
                     target);
            path.pop_back();
        }
    }
    
	 
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {

        sort(num.begin(), num.end());
        
        vector<vector<int>> results;
        vector<int> path;
        
        traverse(results, num, path, 0, 0, target);
        return results;
    }
};

