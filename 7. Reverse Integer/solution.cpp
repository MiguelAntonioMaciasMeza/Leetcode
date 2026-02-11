#include <iostream>
#include <vector>
#include <cmath>


//input ex 1: 123
//output: 321

//input ex 2: -123
//output: -321

//Disregard trailing zeros in input
//input ex 3: 120
//output: 21
class Solution {
    public: 
    long int INT_MAX = std::pow(2, 31);
    long int INT_MIN = -std::pow(2,31) -1;
    
    int reverse(int x){
    }
};

int main(int argc,  char *argv[]){
    Solution sol; 
    sol.reverse(std::stoi(argv[1]));

    return 0;
}