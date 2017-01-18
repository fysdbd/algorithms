
/*******************************************************************************

  First Bad Version

  description(from leetcode
              https://leetcode.com/problems/first-bad-version/
              ):

  You are a product manager and currently leading a team to develop a new product.
  Unfortunately, the latest version of your product fails the quality check.
  Since each version is developed based on the previous version, all the versions after a bad version are also bad.
  Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one,
  which causes all the following ones to be bad.
  You are given an API bool isBadVersion(version) which will return whether version is bad.
  Implement a function to find the first bad version. You should minimize the number of calls to the API.

  notes:

  typical and straightforward binary search problem
  careful about edge cases
  the following way of conditioning
  while ( left + 1 < right )
  is handy and applicable to most other binary search problems as well

  a bit additional note about this problem itself is to be careful of overflow, or it might fail strict test cases, thus
  int mid = left + (right - left) / 2
  should be used, instead of
  int mid = (left + right) / 2

*******************************************************************************/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {

        int left = 1, right = n;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        return isBadVersion(left) ? left : right;
    }
};




