
//Took a while but ended up figuring it out
//Kept a running tally in a seperate array with all possible inputs 0-101
//When pushing back into results, we grab the previous sum, if it's the smallest it would be 0

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        std::vector<int> results;
        std::vector<int> count(101);
        //Summation of total number of frequencies
        for(int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
        }

        
        for(int i = 1; i < 101; i++){
            count[i] = count[i] + count[i-1];
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                results.push_back(0);
            }else{
                results.push_back(count[nums[i] - 1]);
            }
        }
    return results;
    }   
}; 