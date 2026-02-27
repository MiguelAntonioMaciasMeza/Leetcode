class Solution {
public:
    int myAtoi(string s) {
        int result = 0;
        int i = 0; //Pointer for string
        int signFlag = 1; // Positive by default
        bool signChanged = false;
        bool leadingWhiteSpace = true;
        std::queue<int> numQueue;

        //If our left pointer is less than length
        while(i != s.length()){
            
            //Break once hitting a non digit or sign character 
            if(isalpha(s[i]) || s[i] == '.')
                break;
            
            //Handle sign
            if(s[i] == '-' || s[i] == '+'){
                //If Queue is empty means it just assigns sign of result
                if(numQueue.size() == 0 && signChanged == false){
                    signFlag = s[i] == '-' ? -1 : 1;
                    i++;
                    signChanged = true;
                    leadingWhiteSpace = false;
                //If we already have nums in our queue, just break
                }else{
                    break;
                }
            }

            //Add digits to queue increment counter 
            if(isdigit(s[i])){
                leadingWhiteSpace = false;
                numQueue.push(s[i] - 48);
                i++;
            //If just whitespace just increment
            }else if(s[i] == ' ' && numQueue.size() == 0 && leadingWhiteSpace == true){
                i++;
            }else{
                break;
            }
        }

        
        while(numQueue.size() != 0){
            
            //Error bound checking, if the number we're adding is bigger than the remaining amount we're going to add
            //Assign it INT_MAX
            if(result > INT_MAX / 10 || (result == INT_MAX /10 && numQueue.front() > 7)){
                 return result = signFlag == 1 ? INT_MAX : INT_MIN;
                break;
            }else{
            result = result * 10 + numQueue.front();
            }
            numQueue.pop();
        }

        return signFlag * result;
    }
};