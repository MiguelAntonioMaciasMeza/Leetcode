class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int diff = nums.size();

        //Use own index number to help calulate total
        for(size_t i = 0; i < nums.size(); i++){
            diff += i - nums[i];
        }
        return diff;
    }
};