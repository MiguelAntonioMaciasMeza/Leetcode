class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int fixed = 0;
        int left = 0;
        int right = 0;
        int size = nums.size();
        vector<vector<int>> solutions;
        //Lets sort nums first        
        std::sort(nums.begin(), nums.end());
        
        //Loop entire array while fixing one value
        for(; fixed < nums.size() -2; fixed++){
            
            //Avoid duplicates after first iteration, since sorted we compare current index and previous
            if(fixed > 0 && nums[fixed] == nums[fixed-1]) 
                continue;
            left = fixed + 1; 
            right = size -1;  
            
            
            while(left < right){
                int total = nums[fixed] + nums[left] +nums[right];

                //Our current indexes are too large, reduce the larger number 
                if(total > 0){
                    right--;
                
                }//vice versa
                
                else if (total < 0){
                    left++;
                //Triplet found
                }else{
                    solutions.push_back({nums[fixed] ,  nums[left] , nums[right]});
                    
                    //Avoid comparing duplicate numbers 
                    while(left < right && nums[left] == nums[left + 1]){
                        left++;
                    }
                    while(left < right && nums[right] == nums[right - 1]){
                        right--;
                    }

                    left++;
                    right--;
                }
            }
        
        }

        return solutions;
    }
};

    
