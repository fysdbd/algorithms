
/*
    N-Queens II

    Follow up for N-Queens problem.
    Now, instead outputting board configurations, return the total number of distinct solutions.

    notes:
*/

class Solution {
public:
    void helper(int& cnt, vector<int>& board, int curr_index)
    {
        if (curr_index == board.size()) { cnt++; return; }

        // possible candidate vaire sfrom 0 to board.size() - 1
        for (int candidate = 0; candidate < board.size(); candidate++)
        {
            board[curr_index] = candidate;
            bool isValid = true;
            for (int prev = 0; prev < curr_index; prev++) {
                isValid = isValid && (board[prev] != candidate) && (curr_index-prev != abs(board[prev]-candidate));
            }
            if (isValid) { helper(cnt, board, curr_index+1); }
        }
    }

    int totalNQueens(int n)
    {
        int cnt = 0;
        vector<int> board(n, 0);
        
        helper(cnt, board, 0);
        return cnt;
    }
    
};





