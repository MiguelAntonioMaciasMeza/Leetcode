class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        //checking every row of first and last column
        for(int i = 0; i < rows; i++){
            dfs(board, i, 0);
            dfs(board, i, cols-1);
        }

        //Checking every column in first and last row
        for(int j = 0; j < cols; j++){
            dfs(board, 0, j);
            dfs(board, rows -1, j);
        }

        //Flip safe spots, and unsafe spots
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>>& board, int i, int j){
        //Bound checking
        //If not 'O', mark safe and check its neighbors 
        if(i < 0 || i >= board.size() || j >= board[i].size() || j <0 || board[i][j] != 'O')
            return;
        board[i][j] = '#';
        dfs(board, i+1, j);
        dfs(board, i-1, j);
        dfs(board, i, j+1);
        dfs(board, i, j-1);
    }
};