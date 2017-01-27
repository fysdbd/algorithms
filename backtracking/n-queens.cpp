
/*
    N-Queens


    The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.


    Given an integer n, return all distinct solutions to the n-queens puzzle.

    Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

    For example,
    There exist two distinct solutions to the 4-queens puzzle:

    [
     [".Q..",  // Solution 1
      "...Q",
      "Q...",
      "..Q."],

     ["..Q.",  // Solution 2
      "Q...",
      "...Q",
      ".Q.."]
    ]

*/

class Solution {
public:
    void helper(vector<vector<string>>& sols, vector<int>& board, int curr_index)
    {
        // finish and found a solution
        if (curr_index == board.size())
        {
            vector<string> sol(board.size(), string(board.size(), '.'));
            for (int rNum = 0; rNum < board.size(); rNum++) {
                sol[rNum][board[rNum]] = 'Q';
            }
            sols.push_back(sol);
            return;
        }

        // possible candidate vaire sfrom 0 to board.size() - 1
        for (int candidate = 0; candidate < board.size(); candidate++)
        {
            board[curr_index] = candidate;
            bool isValid = true;
            for (int prev = 0; prev < curr_index; prev++) {
                isValid = isValid && (board[prev] != candidate) && (curr_index-prev != abs(board[prev]-candidate));
            }
            if (isValid) { helper(sols, board, curr_index+1); }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> sols;
        vector<int> board(n, 0);
        
        helper(sols, board, 0);
        return sols;
    }
};


