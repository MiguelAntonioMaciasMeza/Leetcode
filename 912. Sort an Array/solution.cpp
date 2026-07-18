#include <ctime>

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        std::srand(std::time({}));
    
        return quickSort(nums, 0, nums.size() - 1);

    }

 
    vector<int> quickSort(vector<int>& nums, int low, int high){
        if (low < high){
            int pivotIndex = partition(nums, low, high);

            //Sort both halves based on pivot index
            quickSort(nums, low, pivotIndex - 1);
            quickSort(nums, pivotIndex + 1, high);

        }

        return nums;
    }

       int partition(vector<int>& nums, int low, int high){
        //Select random index between high and low and set that as pivot, and swap high and with new random index
        int random = rand() % (high - low + 1) + low;

        int temp  = nums[high];
        nums[high] = nums[random];
        nums[random] = temp;
        
        int pivot = nums[high];
        int i = low -1;

        for(int j = low; j < high; j++){
            //current index is smaller than pivot, swap
            if(nums[j] < pivot){
                i++;
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }

        //Swap our highest index to our lowest position to sort
        temp = nums[i + 1];
        nums[i + 1] = nums[high];
        nums[high] = temp;

        return i+1;
    }

};