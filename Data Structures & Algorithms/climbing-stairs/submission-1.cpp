class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp;
        dp.emplace_back(1); // index 0 = 1
        dp.emplace_back(2); // index 1 = 2
        
        for (int i = 2; i < n; ++i) {
            dp.emplace_back(dp[i - 2] + dp[i - 1]);
        }
        return dp[n - 1];
    }
};

/*

index:  0   1      2       3    
        1   1+1    1+1+1   1+1+1+1
            2      2+1     2+1+1  
                   1+2     1+2+1
                           1+1+2
                           2+2
        1   2      3        4

notice that you can get to the first step in 1 way (1 step)
    and that the second step 2 ways (1+1, 2)

notice that in the third step, you can get to it by adding the ways you can
    the # of ways you can get to the i-1 and i-2 steps

for loop starts at i=2 because i=0,i=1 are init to 1 and 2 ways
*/