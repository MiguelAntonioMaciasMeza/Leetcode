class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        //Sort the array first 
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> result;
        std::vector<int> previous = intervals[0];
        
        for(int i = 1; i < intervals.size(); i++){

            //if the smallest index is within previous intervals max
            //Get max range
           if(intervals[i][0] <= previous[1]){
            previous[1] = max(intervals[i][1], previous[1]);

           }else{

            //If not, push previous into result, and set previous interval to the bigger one
            result.push_back(previous);
            previous = intervals[i];
           }
        }
       
    result.push_back(previous);
    return result;
    }
};