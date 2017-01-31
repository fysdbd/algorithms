
/*
    Subsets II

    description(lintcode
                http://www.lintcode.com/en/problem/subsets-ii/
                )

    Given a list of numbers that may has duplicate numbers, return all possible subsets

    Each element in a subset must be in non-descending order.
    The ordering between two subsets is free.
    The solution set must not contain duplicate subsets.

    Example
    If S = [1,2,2], a solution is:

    [
      [2],
      [1],
      [1,2,2],
      [2,2],
      [1,2],
      []
    ]

    notes:
*/

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    void traverse(const vector<int>& nums,
                  vector<vector<int>>& result,
                  vector<int>& path,
                  int index){

        result.push_back(path);
        for (int i = index; i < nums.size(); i++){
            if (i != index && nums.at(i) == nums.at(i-1) ){
                continue;
            }
            path.push_back(nums.at(i));
            traverse(nums, result, path, i+1);
            path.pop_back();
        }
    }
     
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {

        vector<int> nums = S;
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> path;
        traverse(nums, result, path, 0);
        return result;
    }
};



