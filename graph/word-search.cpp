
/*
    Word Search

    Given a 2D board and a word, find if the word exists in the grid.
    The word can be constructed from letters of sequentially adjacent cell,
    where "adjacent" cells are those horizontally or vertically neighboring.
    The same letter cell may not be used more than once.
    For example,
    Given board =

    [
      ['A','B','C','E'],
      ['S','F','C','S'],
      ['A','D','E','E']
    ]
    word = "ABCCED", -> returns true,
    word = "SEE", -> returns true,
    word = "ABCB", -> returns false.

*/

class Solution {
public:
    bool dfs(const vector<vector<char>>& board,
             vector<vector<bool>>& used,
             const string& word,
             int idx,
             int r,
             int c) {
        if (idx >= word.size()) { return true; }

        const vector<vector<int>> diffs = {{1,0},{-1,0},{0,1},{0,-1}};
        for (auto diff : diffs) {
            int newr = r+diff[0], newc = c+diff[1];
            if (0 <= newr && newr < board.size() &&
                0 <= newc && newc < board[0].size() &&
                !used[newr][newc] &&
                board[newr][newc] == word[idx]) {
                used[newr][newc] = true;
                if (dfs(board, used, word, idx+1, newr, newc)) { return true; }
                used[newr][newc] = false;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty() || word.empty()) { return false; }
        int R = board.size(), C = board[0].size();

        vector<vector<bool>> used(R, vector<bool>(C, false));
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (board[r][c] == word[0]) {
                    used[r][c] = true;
                    if(dfs(board, used, word, 1, r, c)) { return true;}
                    used[r][c] = false;
                }
            }
        }
        return false;
    }
};
