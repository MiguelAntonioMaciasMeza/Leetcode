class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int temp = nums[0] + nums[1] + nums[2];
        int size = nums.size();
        std::sort(nums.begin(), nums.end());

        for(int i = 0; i < size -2; i++){
            int left = i + 1;
            int right = size -1;
            
            //Keep track of minimum value and maximum possible value for this loop
            //Prune if we can
            int minSum = nums[i] + nums[i + 1] + nums[i + 2];
            int maxSum = nums[i] + nums[size - 2] + nums[size - 1];
           
            if(minSum >= target){
                if(abs(target - minSum) < abs(target-temp)){
                    temp = minSum;
                }
                //Break out of our loop as our minSum will only get larger
                break;
            }

            if(maxSum <= target){
                if(abs(target - maxSum) < abs(target-temp)){
                    temp = maxSum;
                }
                // For this i, maxSum is the closest we can get, so skip two-pointer
                continue;
            }

            while(left < right){
                
                int sum = (nums[i] + nums[right] + nums[left]);
                if(sum == target)
                    return sum;
                
                //Compare our new sum to temp, if new sum is closer, replace temp 
                temp = abs(target - sum) < abs(target - temp)? sum : temp;
    
                if(sum > target){
                    right--;
                }else if (sum < target){
                    left++;
                }
            }
        }
    
    return temp; 
    }
};