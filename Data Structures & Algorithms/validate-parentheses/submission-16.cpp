#include <stack>
class Solution {

    char closing_to_open(char bracket){
        switch(bracket){
            case ')':
            return '(';
            break;

            case ']':
            return '[';
            break;

            case '}':
            return '{';
            break;

            default:
            return '\0';
            break;
        }
    }
public:
    bool isValid(string s) {
        std::stack<char> the_stack;
        
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                the_stack.push(s[i]);
            }else{
                if(the_stack.empty()){
                    return false;
                }
                if(the_stack.top() == closing_to_open(s[i])){
                    the_stack.pop();
                }else{
                    return false;
                }
            }
        }

        //if its empty, return true
        return the_stack.empty();

    }
};
