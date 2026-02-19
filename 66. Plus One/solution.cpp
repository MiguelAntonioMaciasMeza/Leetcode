class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int end = digits.size() - 1;
        int carryOver = 0;
        vector<int> solution; 

        //Start from last index 
        for(; end >= 0; end--){
            // Start from the last index, incremement by one
            // Keep track of the carrover 
            if (end == digits.size() - 1){
                // If we have a carryover when adding, increase carry over, else just insert into array
                if(digits[end] + 1 == 10){
                    carryOver = 1;
                    solution.emplace(solution.begin(), 0); 
                }else{
                    solution.emplace(solution.begin(), digits[end] + 1);
                }
            }else if (carryOver == 1){
                if(digits[end] + carryOver == 10){
                    carryOver = 1;
                    solution.emplace(solution.begin(), 0);
                }else{
                    carryOver = 0;
                    solution.emplace(solution.begin(), digits[end] + 1);
                }
            }else{
                solution.emplace(solution.begin(), digits[end]);
            }
        }

        //Check if we still have a carryOver remaining
        if(carryOver == 1){
            solution.emplace(solution.begin(), 1);
        }
        return solution;
    }
};