class Solution {
public:

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
};
