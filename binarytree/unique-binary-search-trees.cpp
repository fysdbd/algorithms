
/*
    Unique Binary Search Trees

    Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

    For example,
    Given n = 3, there are a total of 5 unique BST's.

       1         3     3      2      1
        \       /     /      / \      \
         3     2     1      1   3      2
        /     /       \                 \
       2     1         2                 3

*/

class Solution {
public:
    int numTrees(int n) {

        vector<int> count(n+1, 0); count[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int index = 0; index <= i-1; index++) {
                count[i] += count[index]*count[i-1-index];
            }
        }
        return count.back();
    }
};
