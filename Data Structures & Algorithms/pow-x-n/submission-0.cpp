class Solution {
public:
    double myPow(double x, int n) {
        double total = 1;

        if(n>0){
            for(int i=0; i<n; i++){
                total *= x;
            }
        }else{
            for(int i=0; i<abs(n); i++){
                total *= (1/x);
            }
        }

    
        return total;
    }
};
