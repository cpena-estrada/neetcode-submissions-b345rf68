class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) { return nums[0]; }

        return max(helper(0, size-2, nums),
                   helper(1, size-1, nums));
    }

    int helper(int start, int end, vector<int>& nums) {
        int len = (end - start) + 1; // calc len of interval
        if (len == 1) { return nums[start]; } // interval might be too short

        vector<int>dp;
        dp.push_back(nums[start]);
        dp.push_back(max(nums[start], nums[start+1]));

        for (int i = 2; i < len; ++i) {
            dp.push_back(max(nums[i+start] + dp[i-2], dp[i-1]));
        }

        return dp[len-1];
    }
};

/*


same idea as house robber 1

since the last and firs house are neighbors, then you have two possible paths
    - start at 0 and rob until nums.size() - 1
    - start at 1 and rob until nums.size();

          s     e
        0 1 2 3 4       
nums = [2,9,8,3,6]


BOTTOM UP / TABULATION

*/