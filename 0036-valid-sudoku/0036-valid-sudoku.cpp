class Solution{
public:
    bool isValidSudoku(vector<vector < char>> &board)
    {
        for (int k = 0; k < 9; k++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[k][j] != '.')
                {
                    char m = board[k][j];
                    for (int i = 0; i < 9; i++)
                    {
                        if (board[k][i] == m && i!=j)
                        {
                            return false;
                        }
                        if(board[i][j]==m && i!=k){
                            return false;
                        }
                        if (board[3 *(k / 3) + (i / 3)][3 *(j / 3) + (i % 3)] == m && (3 *(k / 3) + (i / 3))!=k && (3 *(j / 3) + (i % 3))!=j)
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    };