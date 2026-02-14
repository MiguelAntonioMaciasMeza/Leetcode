class Solution {
public:
    string intToRoman(int num) {
        string output = "";
        // std::unordered_map<int, string> romanMap{
        //     {1,"I"},
        //     {4,"IV"},
        //     {5,"V"},
        //     {9,"IX"},
        //     {10,"X"},
        //     {40,"XL"},
        //     {50,"L"},
        //     {90,"XC"},
        //     {100,"C"},
        //     {400,"CD"},
        //     {500,"D"},
        //     {900,"CM"},
        //     {1000,"M"}
        // };
        vector<pair<int, string>> romanPairs = {
            {1,"I"},
            {4,"IV"},
            {5,"V"},
            {9,"IX"},
            {10,"X"},
            {40,"XL"},
            {50,"L"},
            {90,"XC"},
            {100,"C"},
            {400,"CD"},
            {500,"D"},
            {900,"CM"},
            {1000,"M"}

        };
        
        for(int i = romanPairs.size() - 1; i >= 0;){
            if(num >= romanPairs[i].first) {// value 
                output += romanPairs[i].second;//roman number
                num -= romanPairs[i].first;
                continue; // Avoid deincremting and check if num >= value
            }
            //Deincrement value if our num is smaller
            i--;
        }

        return output;
    }
};