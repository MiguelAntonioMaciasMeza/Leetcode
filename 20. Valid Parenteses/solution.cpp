class Solution {
public:
    bool isValid(string s) {
        //3 Rules
        //Brackets must be closed by same type
        //Open brackets must be closed in correct order
        //Every close bracker has a corresponding open bracket 

        std::stack<char> stack;

        int len = s.length();

        for(size_t i = 0; i < len; i++){
            //First valid open
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stack.push(s[i]);
                continue;
            }else if(s[i] == ')'||s[i] == '}' || s[i] == ']'){

                //Trying to close if nothing is in the stack
                if(stack.empty()){
                    return false;

                }else{

                    if(s[i] == ')'){
                        if(stack.top() == '('){
                            stack.pop();
                            continue;
                        }else{
                            return false;
                        }
                    }else if (s[i] == '}'){
                        if(stack.top() == '{'){
                            stack.pop();
                            continue;
                        }else{
                            return false; 
                        }
                    }else if (s[i] == ']'){
                        if(stack.top() == '['){
                            stack.pop();
                            continue;
                        }else{
                            return false;
                        }
                    }
                }
            }
          
        }
        return stack.empty() ? true : false;
    }
};