class Solution {
public:
    int reverse(int x) {
        int isNegative = x > 0 ? 1: -1;
        int rev = 0;
        //Basic check
    

        if(x == 0){
            return 0;
        }

        while(x != 0){
            //Retrieve last digit
             int digit = (x % 10); 
             x = floor(x/10);
             
             //Error bound positive check
             //First checks if next multiple of 10 would go out of bounds if positive 
             if(rev > INT_MAX / 10 || (rev == INT_MAX/10 && digit > 7)) //Digit is for edge cases 
                return 0;
            //next multiple of 10 would go out of bounds if positive
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit > 8)) 
                return 0;
             rev = (rev*10) + digit; 
        }
        return rev;
    }
};