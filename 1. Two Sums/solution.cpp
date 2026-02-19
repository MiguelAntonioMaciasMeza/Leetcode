class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> solution;
        unordered_map<int, int> numMap; //Where k = val, and value = index

        for(int i = 0; i < nums.size(); i++){

            //Check if the target value is already in the hast table
            //If so, return index i and index from hash table

            //If we find the requested value push back indexes to solution
            if(numMap.find(target - nums[i]) != numMap.end()){
                solution.push_back(numMap.at(target - nums[i]));
                solution.push_back(i);
                break;
            }
            //Else place the value and index in the numMap 
            numMap.emplace(nums[i], i);
            
        }
        return solution;
    }
};