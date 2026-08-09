class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();
        int effectiveK = k % length;

        if(effectiveK == 0)
            return;

        for(int i = 0; i < length/2; i++){
            int temp = nums[i];
            nums[i] = nums[length-1-i];
            nums[length-1-i] = temp;
        }

        for(int i = 0; i < effectiveK/2; i++){
            std::swap(nums[i], nums[effectiveK -i-1]);
            
        }
        int left = effectiveK;
        int right = length -1;
        for(int i = 0; i < (length - effectiveK)/2 ;i++){
             std::swap(nums[left], nums[right]);
             left++;
             right--;
        }
    }
};