class Solution {
public:
    string intToRoman(int num) {
        string output = "";
        std::unordered_map<int, string> romanMap{
            {1,"I"},
            {4,"IV"},
            {5,"V"},
            {9,"IX"},
            {10,"X"},
            {40,"XL"},
            {50,"L"},
            {90,"XC"},
            {100,"C"},
            {400,"CD"},
            {500,"D"},
            {900,"CM"},
            {1000,"M"}
        };

        int digit = 1000;
        while(num > 0){
           
            
            if(num / digit == 0){
                digit = digit / 10;
            }else{
                    //Additive form, greater than 5, and less than 9
                    if(num / digit >= 5 && num / digit < 9 ){
                    output = output + romanMap[5 * digit];
                    num -= digit * 5;    
                    
                    //Subtractive form either 4 or 9
                    }else if(num / digit == 4 || num / digit == 9){

                        output = output + romanMap[(num / digit )* digit];
                        num -= (num / digit) * digit;
                    
                    //Powers of ten, less than 5 but not greater than 4
                    }else{
                        output = output + romanMap[digit];
                        num -= digit;
                    }
            }
        }
        return output;
    }
};