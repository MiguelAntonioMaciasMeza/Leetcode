class Solution {
public:
    int strStr(string haystack, string needle) {
        int hayIndex = 0;
        int needleIndex = 0;
    
        //Iterate through the whole word 
        while(hayIndex <= haystack.length() - 1){
            //h[index] == n[index]
            if(needle[needleIndex] == haystack[hayIndex]){
                //Check if both have same length
                //If so return the difference since we're looking for the starting index

                if(needleIndex == needle.length() - 1){
                    return hayIndex - needleIndex;
                }

                //If it doesn't match in length, increase both indexes
                //since we need to check next index
                needleIndex += 1;
                hayIndex += 1;
            }else{
                //set hayIndex to last starting index and reset needleIndex to zero
                hayIndex = hayIndex - needleIndex + 1;
                needleIndex = 0;
            }
        }
        //If loop ends it means that no positions were found;
        return -1;
    }
};