class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.length() - 1;
        int count = 0;

        for(size_t i = 0; i < s.length(); i++){
            //String is empty at the end
            if(s[end] == ' '){
                //Update end pointer
                end--;

                //If there is an empty space and it's not the last index break out of loop
                //We expect atleast one word, so count must be larger than 1
                if(end != s.length() - 1 && count >= 1){
                    break;
                }
                continue;
            }else{
                //An actual letter in the string
                count++;
                end--;
            }
        }

        return count;
        
    }
};