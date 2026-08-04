class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        std::vector<std::vector<int>> dp(grid.size(), std::vector<int>(grid[0].size(), -1));
        
        findPath(grid, dp,0,0);
          
        return dp[0][0];
    }


    void findPath(vector<vector<int>>& grid, vector<vector<int>>& dp, int row, int col){
        //printf("loop\n");
        if(row == grid.size() || col == grid[0].size())
            return;

        //Been here already return early
        if(dp[row][col] > -1){
            return;
        }
        
        
        findPath(grid,dp,row + 1,col);//Go down
        findPath(grid,dp,row,col + 1);//Go right
        
        if(row == grid.size() - 1 || col == grid[0].size() - 1){
            //Last row
            if(row == grid.size() - 1 && col != grid[0].size() -1){
                dp[row][col] = grid[row][col] + dp[row][col + 1];
            
            //Last col
            }else if(row != grid.size() - 1 && col == grid[0].size() -1) {
                dp[row][col] = grid[row][col] + dp[row+1][col];
            //Last row/col
            }else{
                dp[row][col] = grid[row][col];
            }
        }else{
            dp[row][col] = grid[row][col] + min(dp[row + 1][col], dp[row][col + 1]);
        }

    }
};