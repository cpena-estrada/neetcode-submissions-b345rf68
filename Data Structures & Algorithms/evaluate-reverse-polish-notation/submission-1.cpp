#include <stack>
class Solution {
public:
    //go though tokens
    //get numbers, convert to ints and push them into the stack
    //do so by getting the number and subtracting 0 (ASCII) or stoi()
    //when you encounter an operator send pop1 and pop2 and the operator to a func
    //func takes care of the math with a switch statement
    //fun returns int value that we will accumulate in ans

    int do_math(int pop1, int pop2, string op){
        
        switch(op[0]){
            case '+':
            return pop1+pop2;
            break;

            case '-':
            return pop2-pop1;
            break;

            case '*':
            return pop1*pop2;
            break;

            case '/':
            return pop2/pop1;
            break;

            default:
            //
            break;

            return -1;
        }
    }

    int evalRPN(vector<string>& tokens) {
        
        stack<int> the_stack; 
        int ans = 0;

        for(int i=0;i<tokens.size(); i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                int num  = stoi(tokens[i]);
                the_stack.push(num);
               }else{
                int pop1 = the_stack.top();
                the_stack.pop();
                int pop2 = the_stack.top();
                the_stack.pop();

                the_stack.push(do_math(pop1,pop2, tokens[i]));
               }
        }

        return the_stack.top();
    }
};
//tokens[i][0]-1;
