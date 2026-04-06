class Solution {
public:


    int rob(vector<int>& nums) {
        vector<int> table(nums.size(), 0);
        table[0] = nums[0];
        table[1] = max(nums[1], nums[0]); // ROB ONLY THE BEST ONE for the first 2 houses

        for (int i = 2; i < nums.size(); i++) {
            int current = nums[i];
            int most = max(table[i-1], current + table[i-2]);
            table[i] = most;
        }
        return table[table.size() - 1];
    }
};


/*
dfs:

        unordered_map<int,int> cache;

    int dfs(int i, vector<int>& nums) {
        if (i >= nums.size()) { return 0; }

        if (cache.count(i)) { return cache[i]; }

        // take current and i + 2
        int take = nums[i] + dfs(i + 2, nums);
        //skip curr
        int skip = dfs(i + 1, nums);
        
        // take max
        cache[i] = max (take, skip);
        return cache[i];
    }

    int rob(vector<int>& nums) {
        return dfs(0, nums);
    }


*/
