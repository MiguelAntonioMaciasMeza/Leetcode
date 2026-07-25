class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix.size();

        //Go through each row 
        for(int i =0; i < row; i++){
            //Only necessary to go to half the matrix
            for(int j = i; j< col; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        //Reverse the rows
        for(int i = 0; i <row; i++){
            //col/2 since in odd matrices, we dont reverse middle element
            for(int j = 0; j < col/2; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][col-1-j];
                matrix[i][col-1-j] = temp;
            }
        }
    }
};