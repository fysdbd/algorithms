
/*
    Triangle

    Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

    For example, given the following triangle
    [
         [2],
        [3,4],
       [6,5,7],
      [4,1,8,3]
    ]
    The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

    Note:
    Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        for (int level = 1; level < triangle.size(); level++)
        {
            triangle[level][0] += triangle[level-1][0];
            triangle[level][level] += triangle[level-1][level-1];
            for (int i = 1; i < triangle[level].size()-1; i++) {
                triangle[level][i] += min(triangle[level-1][i-1], triangle[level-1][i]);
            }
        }
        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};

