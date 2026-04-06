class Solution {
private:
    unordered_map<int, int> cache;

    bool dfs(int i, vector<int>& nums) {
        if (i == nums.size() - 1) { return cache[i] = true; } // last index

        int range = nums[i];

        for (int j = 1; j <= range; j++) {
            int jump_index = i + j;
            if (jump_index < nums.size()) { // if within bounds, try it
                if (dfs(jump_index, nums)) { cache[i] = true; return cache[i]; } // return true only if call suceeds
                                                            // call is false, nothing happens. keep iterating
                                                            // prevents early stopping like in index 2
            }
        }

        cache[i] = false;
        return cache[i]; // only gets here after all jumps fail
    }
public:

    bool canJump(vector<int>& nums) {
        dfs(0, nums);
        return cache[0];
    }
};

/*

reach last index
   i i
[2,1,3,0,0,0]

iterate over 1 to n inclusive
    call dfs on thar range, but make sure you dont go oob
    make sure you dont go oob

DFS (No memo):

class Solution {
private:
    bool dfs(int i, vector<int>& nums) {
        if (i == nums.size() - 1) { return true; } // last index

        int range = nums[i];

        for (int j = 1; j <= range; j++) {
            int jump_index = i + j;
            if (jump_index < nums.size()) { // if within bounds, try it
                if (dfs(jump_index, nums)) { return true; } // return true only if call suceeds
                                                            // call is false, nothing happens. keep iterating
                                                            // prevents early stopping like in index 2
            }
        }

        return false; // only gets here after all jumps fail
    }
public:

    bool canJump(vector<int>& nums) {
        return dfs(0, nums);
    }
};
*/