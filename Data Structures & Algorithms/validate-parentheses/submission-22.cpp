class Solution {
public:

    // input is closed, output is open -> compare to top of stack
    unordered_map<char, char> close_to_open = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    bool isValid(string s) {
        if (s.length() == 0) { return true; }
        stack<char> the_stack;

        for (const auto& c : s) {
            if (c == '(' || c == '{' || c == '[') { // if bracket is open
                the_stack.push(c);
                continue;
            }
            
            if (!the_stack.empty() && close_to_open[c] == the_stack.top()) { // if bracket is closed
                the_stack.pop();
            } else {
                return false; // mismatch, not valid
            }
        }

        if (!the_stack.empty()) { return false; }

        return true;
    }
};



/*

helper global dict mapping 

iterate over string
    if its open,
        push onto stack
        continue

    if its closed
        check if top of stack is of same kind
        if it is
            pop it 
            continue
        else if it isnt
            return false

if the stack is not empty
    return false

return true
"("
")"

original solution:
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


*/
