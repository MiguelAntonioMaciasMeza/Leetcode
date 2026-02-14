class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      //Last valid Index

      //[1,2,2,3,4,5,5]
      int k = 0;
      for(size_t i = 1; i < nums.size(); i++ ){
        //Is the number infront different than the number before?
        if(nums[i] != nums[k]){
            //Overwrite the previous number
            k++;
            nums[k] = nums[i];
            }
        }
    //Add one since we are counting unique numbers
    return k + 1;
    }
}; 