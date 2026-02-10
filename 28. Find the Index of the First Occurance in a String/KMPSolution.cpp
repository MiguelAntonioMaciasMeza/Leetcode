class Solution {
public:
    int strStr(string haystack, string needle) {
        int hayIndex = 0;
        int needleIndex = 0;
        std::vector<int> lps = computeLPS(needle);

        //Iterate through the whole word 
        while(hayIndex <= haystack.length() - 1){
            //h[index] == n[index]
            if(needle[needleIndex] == haystack[hayIndex]){
                

                //If the last comparision is the same length as our substring return the index that it starts on
                if(needleIndex == needle.length() - 1){
                    return hayIndex - needleIndex;
                }

                //Else increase both indexes 
                hayIndex += 1;
                needleIndex += 1;
            }else{
                //If our substring  index is greater than one see if we have a value in our LPS table
                if(needleIndex != 0){
                    //Update our substring index based if it's in our LPS
                    needleIndex = lps[needleIndex - 1];
                }else{
                    //If needle index is zero than we just increase our word index
                    hayIndex++;
                }
             
            }
        }
        //If loop ends it means that no positions were found;
        return -1;
    }

    std::vector<int> computeLPS(string needle){
        int n = needle.length();
        int i = 1; //We move forward while checking if we match with our second pointer j
        int j = 0; // Starts at the beginning, also length of previous substring
        std::vector<int> lps = std::vector(n, 0);
        while(i < n){

            //If the index infront is the same as the previous prefix match
            if(needle[i] == needle[j]){
                //Add to prefixLen
                j++;
                //Assign our current position the new prefixLen 
                lps[i] = j;
                //Increment i
                i++;
            
            //No prefix match
            }else{
                //However if we do have a prefix value make sure to update it
                if(j != 0){

                    //Make prefix length the previous index so if our prefix was 2 -> 1, or 3->2
                    //Only if we already had a prefix being matched
                    j = lps[j - 1];
                
                //If we don't 
                }else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;

    }
};