class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
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
    }
};

/*

 0 1 2 3
[1,2,3]

3
- 3+2+1 = 6
- 2 = 1

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



*/