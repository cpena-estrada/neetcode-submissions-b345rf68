class Solution {
private:
public:

    //   index     nums arr     # jumps so far    res to update
    void dfs(int i, vector<int>& nums, int jumps, int& min_jumps) {
        if (i >= nums.size() - 1) {
            min_jumps = min(min_jumps, jumps); // means you made it to or past last index
            return; // stop looking as first time you reach last index would be using the greatest jump possible (min)
        }

        int range = nums[i]; 

        //try biggest jump distance first
        for (int j = range; j >= 1; j--) {
            int jump_index = i + j;
            if (jump_index < nums.size()) {
                dfs(jump_index, nums, jumps + 1, min_jumps);
            }
        }

    }
    int jump(vector<int>& nums) {
        int min_jumps = nums.size();
        dfs(0, nums, 0, min_jumps);
        return min_jumps;
    }
};
