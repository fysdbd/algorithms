
/*******************************************************************************

  Sqrt(x)

  description(from leetcode
	      https://leetcode.com/problems/sqrtx/
	      )
  Implement int sqrt(int x).
  Compute and return the square root of x.

  comments:
  typical practical use of binary search
  pay attention to integer overflow case.
  rest is straightforward

*******************************************************************************/

class Solution {
public:
    int mySqrt(int x) {
        
        int left = 0, right = x;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            long long square = ((long long) mid) * mid;
            (square > x ? right : left) = mid; 
        }
        
        long long square = ((long long) right) * right;
        return (square <= x ? right : left);
    }
};

