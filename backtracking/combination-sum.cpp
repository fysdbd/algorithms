
/*
    Combination Sum

    description(lintcode:
                http://www.lintcode.com/en/problem/combination-sum/
                )

    Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
    The same repeated number may be chosen from C unlimited number of times.

    For example, given candidate set 2,3,6,7 and target 7, 
    A solution set is: 
    [7] 
    [2, 2, 3] 

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.
    Have you met this question in a real interview? Yes
    Example
    given candidate set 2,3,6,7 and target 7, 
    A solution set is: 
    [7] 
    [2, 2, 3]
    
    notes:
*/

class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
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
            path.push_back(candidates[idx]);
            traverse(results,
                     candidates,
                     path,
                     idx,
                     acc + candidates[idx],
                     target);
            path.pop_back();
        }
    }
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        
        set<int> candidate_set(candidates.begin(), candidates.end());
        vector<int> unique_candidates;
        unique_candidates.assign(candidate_set.begin(), candidate_set.end());
        
        vector<vector<int>> results;
        vector<int> path;
        
        traverse(results, unique_candidates, path, 0, 0, target);
        return results;
    }
};
