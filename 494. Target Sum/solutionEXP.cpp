class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        if(nums.size() == 1){
            if(nums[0] == abs(target)){
                return nums[0] == (target) && -nums[0] == target? 2 : 1;
            }else{
                return 0;
            }
        }

        int count = 0;
        int index = 0;
        int sum = 0;
        backTrack(nums,count,sum, index,target);

        return count;
    }

    void backTrack(vector<int>& nums,int& count, int sum, int index, int target){
        if(index == nums.size()){
            if(target == sum)
                count++;
                return;
        }

        backTrack(nums, count, sum - nums[index], index + 1, target);
        backTrack(nums, count, sum + nums[index], index + 1, target);
    }
};