
/*
    Coin Change

    You are given coins of different denominations and a total amount of money amount.
    Write a function to compute the fewest number of coins that you need to make up that amount.
    If that amount of money cannot be made up by any combination of the coins, return -1.

    Example 1:
    coins = [1, 2, 5], amount = 11
    return 3 (11 = 5 + 5 + 1)
    Example 2:
    coins = [2], amount = 3
    return -1.

    Note:
    You may assume that you have an infinite number of each kind of coin.

*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> nums(amount+1, -1); nums[0] = 0;
        for (int val = 1; val <= amount; val++) {
            for (int coin_val : coins) {
                if (val < coin_val || nums[val-coin_val] == -1) { continue; }
                if (nums[val] == -1 || nums[val-coin_val]+1 < nums[val])  {
                    nums[val] = nums[val-coin_val]+1;
                }
            }
        }

        return nums.back();
    }
};
