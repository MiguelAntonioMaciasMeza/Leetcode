class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> combinations;

        backTrack(combinations, "",0,0, n);


        return combinations;


        
    }

    void backTrack(vector<string>& combinations,string path,int open, int close, int n){

        //Add a base case, we know all valid combinations will be atleast n*2 in length
        if(n * 2 == path.length()){
            combinations.push_back(path);

        //Branch isn't up to length so not valid 
        }else{

            //Keep open brackets as long as its < n
            if(open < n){
                backTrack(combinations, path + '(', open + 1, close, n);

                //Close internal parentheses as long as it can
                if(close < open){
                    backTrack(combinations, path + ')', open, close + 1,n);
                }

            //All brackets are open, close the remaining
            }else if(close < open){
                backTrack(combinations, path + ')', open, close + 1, n);
            }
        }
    

    }

};