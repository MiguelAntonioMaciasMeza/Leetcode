class Solution {
public:
    int uniquePaths(int m, int n) {
        int paths[m][n];

        for(int i = 0; i < m; i++){

            for(int j = 0; j <n; j++){
                if(i == 0){
                    paths[0][j] = 1;
                }
                if(j == 0){
                    paths[i][j] = 1;
                }
                
                if(i != 0 && j != 0){
                    paths[i][j] = paths[i-1][j] + paths[i][j-1];  
                }
            }
        }

    
        return paths[m-1][n-1];
    }
};