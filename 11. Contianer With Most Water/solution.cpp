class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;
        int tempWater = 0;
        //Stop when either index is pointing to each other
        while(left < right){
            if(height[left] < height[right]){
                tempWater = height[left] * (right - left);
                maxWater = tempWater > maxWater? tempWater: maxWater;
                left++;
            }else{
                tempWater = height[right] * (right - left);
                maxWater = tempWater > maxWater? tempWater: maxWater;
                right--;
            }
        }

        return maxWater;
    }

};