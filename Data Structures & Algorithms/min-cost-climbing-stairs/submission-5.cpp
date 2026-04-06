class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp;
        int n = cost.size();
        dp.emplace_back(cost[0]);
        dp.emplace_back(cost[1]);

        for (int i = 2; i < n; ++i) { 
            dp.emplace_back(min(cost[i] + dp[i-1],
                                cost[i] + dp[i-2]));
        }

        return min(dp[n-1], dp[n-2]);
    }
};

/*

 0 1 2 3
[1,2,3]

 0 1 2 3 4
[1,2,3,4]

4+3+2+1 = 10

minimize the paths
    path starting from 0
    path starting from 1

    for any given path i
        try going i+1
        try going i+2





instead of starting from 0 or 1, start at n-1

accxumulate costs until index base case (index 0 and 1)

solution but its chopped. should break because im accessing cost[n] oob
maybe just append a zero to cost before call

        unordered_map<int,int> cache;
        int n = cost.size();
        int total = 0;
        cache[0] = cost[0];
        cache[1] = cost[1]; //init base cases

        return dfs(n, cache, cost);
    }

    // pass in size of cost to compare for base case againt index i

    int dfs(int n, unordered_map<int,int>& cache, vector<int>& cost) {
        if (n < 2) { return cost[n]; }
        if (cache.count(n)) { return cache[n]; }

        int left = cost[n] + dfs(n-1, cache, cost);
        int right = cost[n] + dfs(n-2, cache, cost);

        cache[n] = min(left, right);
        return cache[n];
    }

PROPER WAY:

        unordered_map<int,int> cache;
        return min(dfs(0, cache, cost), dfs(1, cache, cost)); // start 0 or 1
    }

    // pass in size of cost to compare for base case againt index i

    int dfs(int i, unordered_map<int,int>& cache, vector<int>& cost) {
        if (i >= cost.size()) { return 0; } // stops recursion
        if (cache.count(i)) { return cache[i]; }

        int left = cost[i] + dfs(i+1, cache, cost); 
        int right = cost[i] + dfs(i+2, cache, cost);

        cache[i] = min(left, right);
        return cache[i];

BOTTOM UP ARRAY:
        // min cost to reach ith step!
        // you build the answer up to n
        // unlike recursive approach where you calc costs until you reach the end strarting from 0 and from 1 
        vector<int> dp;
        int n = cost.size(); //zero indexing [1,2] -> n=3 
        dp.emplace_back(cost[0]);
        dp.emplace_back(cost[1]);

        // <= n because you want to go past the last step (aka size of cost) and calculate it
        // if you didint go past, you wouldnt be caluclating it
        for (int i = 2; i <= n; ++i) { 
            dp.emplace_back(min(cost[i] + dp[i-1],
                                cost[i] + dp[i-2]));
        }

        return dp[n]; // n because you want to know the cost past the last step
                      // we build very last cost in the loop (<=n)

*/