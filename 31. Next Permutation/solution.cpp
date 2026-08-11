class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1)
            return;
        int n = nums.size();
        int pivot = -1;

        //Find pivot
        for(int i = n-2; i >= 0; i--){
           if(nums[i] < nums[i+1]){
            pivot = i;
            break;
           }
        }

        //If no pivot found, array in lowest possible order, put it in acesnding order
        if(pivot == -1){
            std::reverse(nums.begin(), nums.end());
            return;
        }
        
        //We know that everything from end to pivot will be accensding,
        //we just need the first value where it is larger than pivot
        for(int i = n -1; i > pivot; i--){
            if(nums[i] > nums[pivot]){
                std::swap(nums[i], nums[pivot]);
                break;
            }
        }
       
        //Reverse everything past the pivot
        std::reverse(nums.begin() + pivot + 1, nums.end());
    }
};