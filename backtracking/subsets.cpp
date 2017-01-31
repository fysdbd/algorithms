
/*
    Subsets

    description(lintcode
                http://www.lintcode.com/en/problem/subsets/
                )

    Given a set of distinct integers, return all possible subsets.

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

    Example
    If S = [1,2,3], a solution is:

    [
      [3],
      [1],
      [2],
      [1,2,3],
      [1,3],
      [2,3],
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
    void traverse(vector<int>& nums,
                  vector<vector<int>>& result,
                  vector<int>& path,
                  int index){

        result.push_back(path);
        for (int i = index; i < nums.size(); i++){
            path.push_back(nums.at(i));
            helper(nums, result, path, i+1);
            path.pop_back();
        }
    }
     
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> path;
        traverse(nums, result, path, 0);
        return result;
    }
};

