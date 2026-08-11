class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> paths(2, std::vector<int> (n));

        for(int i = 0; i < m; i++){

            for(int j = 0; j <n; j++){
                if(i == 0 || j == 0){
                    paths[i%2][j] = 1;
                }
                
                if(i != 0 && j != 0){
                    if(i % 2 == 1){
                    paths[1][j] = paths[0][j] + paths[1][j-1];
                    }else{
                    paths[0][j] = paths[1][j] + paths[0][j-1];
                    }  
                }
            }
          
        }

        return m % 2 == 0 ? paths[1][n-1] : paths[0][n-1];
    }
};