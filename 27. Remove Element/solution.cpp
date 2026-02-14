class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //If we have an empty vector just return zero
        if(nums.empty()){
            return 0;
        }
        
        //If our size is only one test if its valid or not
        if (nums.size() == 1){
            if (nums[0] == val){  
                return 0;
            }else{
                return 1;
            }
        }


        //i = start of vector, k = end of vector
        int k = nums.size();
        int i = 0;


        // two pointers, i = left , k = right
        //Has to be equals just incase the whole vector is val,
        while(i <= k - 1){
            //If not val in left pointer increase left
            if(nums[i] != val){
                i++;

            //Else left pointer == val
            }else{
                //Check to see if right pointer is equal to val, if so, deincrement
                if(nums[k - 1] == val){
                    k--;
               
               //If not replace what is in left pointer with what right has stored in
                }else{
                    nums[i] = nums[k - 1];
                    k--;
                }
            }
        }
        //total count 
        return k;
    }
};