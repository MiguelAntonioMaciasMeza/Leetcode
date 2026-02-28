class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign = ((dividend < 0) != (divisor < 0)) ? true : false;

        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        else if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;

        //Convert to long first than get absolute
        long  a = dividend;
        long  b = divisor;

        a = abs(a);
        b = abs(b);


        long  quotient = 0;
        for(int i = 31; i >=0; i--){

            //If our shifted number is less than or equal to our dividened
            //We subtract our diviendend by that value, and keep track of our quotient by or
            if((b << i) <= a){
                a -= (b << i);
                quotient += 1L << i; //Add a long bit that is shifted i amount (2^i)
            }
        }
    
        return sign ? -quotient : quotient; 
    }
};