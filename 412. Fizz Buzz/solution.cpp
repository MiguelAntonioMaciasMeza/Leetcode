class Solution {
public:
    vector<string> fizzBuzz(int n) {
        std::vector<string> answer(n);
        while(n > 0){
            //If divisiable by 3 and 5 is the same as 3 * 5 
            if( n % 15 == 0)
                answer[n - 1] = "FizzBuzz";
            else if(n % 3 == 0)
                answer[n - 1] = "Fizz";
            else if(n % 5 == 0)
                answer[n - 1] ="Buzz";
            else
                answer[n - 1] = to_string(n);
            n--;
        }

        return answer; 
    }
};