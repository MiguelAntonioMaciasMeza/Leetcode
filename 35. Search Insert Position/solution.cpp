class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;
        int midpoint = 0;
        while(low <= high){
            midpoint = low + (high - low ) / 2;

            if (nums[midpoint] == target){
                return midpoint;
            //Ignore left half if smaller
            }else if (nums[midpoint] < target){
                low = midpoint + 1;

            //Ignore right half if bigger
            }else{
                high = midpoint - 1;
            }
        }
        
        //Target not found in the vector
        //Check if current num is larger or smaller, adjust midpoint if needed

        return nums[midpoint] < target ? midpoint + 1: midpoint;
    }

};