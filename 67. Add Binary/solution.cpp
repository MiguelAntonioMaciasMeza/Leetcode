class Solution {
public:
    string addBinary(string a, string b) {
        int aLen = a.length() - 1; //Used For Indexing A
        int bLen = b.length() - 1; //Used For Indexing B
        int carry = 0;  //Keeps track of carry
        string output = "";
        while(aLen >= 0 ||  bLen >= 0 || carry){
            if(aLen >= 0){
                carry += a[aLen--] - '0';// char 'math' if '1' - '0' = 1 if '0' - '0' = 0
            }

            if(bLen >= 0){
                carry += b[bLen--] - '0';
            }
            output += carry % 2 + '0'; //if we   
            carry /= 2; //We reset the carryover by dividing by 2, if we have a carry over it goes till our next iteration, if we have no carry over it stays zeroed
        }
        reverse(output.begin(), output.end());
        return output; 
        }  
    };
