class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int,int> cache;
        return dfs(n, cache);
    }

    int dfs(int n, unordered_map<int,int>& cache) {
        if (n <= 2) { return n; }
        if (cache.count(n)) { return cache[n]; }
        cache[n] = dfs(n-1, cache) + dfs(n-2, cache);
        return cache[n];
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

solution with a dynamic vector:
        vector<int> dp;
        dp.emplace_back(1); // index 0 = 1
        dp.emplace_back(2); // index 1 = 2
        
        for (int i = 2; i < n; ++i) {
            dp.emplace_back(dp[i - 2] + dp[i - 1]);
        }
        return dp[n - 1];

dfs:
at each step, you can take 1 or 2 steps

                  0
              /       \
             1         2
            /\        / \
           2  3      3   4
          /\        / \  / \
         3  4      4  5  5  6
        / \
       4   5

       3
      / \
     2   1 base cases

             4
           /    \
          3      2 base
         / \     
        2   1   base

you can get to the 4th step in 3 + 2 ways

*/