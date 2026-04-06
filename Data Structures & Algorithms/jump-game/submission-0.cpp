class Solution {
private:
    bool dfs(int i, vector<int>& nums) {
        if (i == nums.size() - 1) { return true; } // last index

        int range = nums[i];

        for (int j = 1; j <= range; j++) {
            int jump_index = i + j;
            if (jump_index < nums.size()) { // if within bounds
                if (dfs(jump_index, nums)) { return true; } 
            }
        }

        return false;
    }
public:

    bool canJump(vector<int>& nums) {
        return dfs(0, nums);
    }
};

/*

reach last index
   i i
[2,1,3,0,0,0]

iterate over 1 to n inclusive
    call dfs on thar range, but make sure you dont go oob
    make sure you dont go oob


*/