class Solution {
public:
    string reverseOnlyLetters(string s) {
        int start = 0;
        int end  = s.length() - 1;

        //If start is greater than end that means we've gone through the whole string
        while(start < end){
            if(isalpha(s[end]) && isalpha(s[start])){
                char temp = s[start];
                s[start]  = s[end];
                s[end] = temp;
                start++;
                end--;
            }else{
                if(!isalpha(s[start]))
                    start++;
                else if(!isalpha(s[end]))
                    end--;
            }

        }
        return s;
        
    }
};