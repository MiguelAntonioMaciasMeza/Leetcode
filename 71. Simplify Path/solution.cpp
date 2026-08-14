#include <cctype>
class Solution {
public:
    string simplifyPath(string path) {
        std::stringstream ss(path);
        std::string token;
        std::vector<string> dir;

        while(getline(ss,token, '/')){
            if(token == ".."){
                if(dir.size() >0){
                    dir.pop_back();
                }
            }else{
                if(token != "." && token != "")
                    dir.push_back(token);      
            }
        }

        string result = "";
        for(int i = 0; i < dir.size(); i++){
            result += "/" + dir[i];
        }
       return result.length() == 0 ? "/" : result;
    }
};