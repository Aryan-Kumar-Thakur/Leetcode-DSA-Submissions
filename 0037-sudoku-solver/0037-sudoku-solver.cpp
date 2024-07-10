class Solution {
    bool issafe(vector<vector<char>>& board, int r, int c, char num) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == num || board[i][c] == num) {
                return false;
            }
            if (board[3 * (r / 3) + (i / 3)][3 * (c / 3) + (i % 3)] == num) {
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board, int ind) {
        for (int ind = 0; ind < 9; ind++) {
            for (int i = 0; i < 9; i++) {
                if (board[ind][i] == '.') {
                    for (int j = 1; j < 10; j++) {
                        char x = j + '0';
                        if (issafe(board, ind, i, x)) {
                            board[ind][i] = x;
                            if(solve(board, ind + 1)){
                                return true;
                            }
                            else{
                                board[ind][i] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) { solve(board, 0); }
};