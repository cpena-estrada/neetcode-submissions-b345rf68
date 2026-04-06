class Solution {

public:

    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) { return true; }

        int goal_index = nums.size() - 1;
        bool can_reach = false;

        // stop at index 1 since you are checking i - 1
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i - 1] + i - 1 >= goal_index) { // can reach from previous index
                goal_index = i - 1; // update goal index
                can_reach = true;
            }
            else {
                can_reach = false;
            }

        }

        return can_reach;
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

DFS WITH MEMO:

class Solution {
private:
    unordered_map<int, bool> cache;

    bool dfs(int i, vector<int>& nums) {
        if (i == nums.size() - 1) { cahce[i] = true; return cache[i]; } // last index

        if (cache.count(i)) { retrun cache[i]; } // if alr explored, just return it

        int range = nums[i];

        for (int j = 1; j <= range; j++) {
            int jump_index = i + j;
            if (jump_index < nums.size() && dfs(jump_index, nums)) { // if within bounds, try it. and if path returns true, cache and return
                cache[i] = true;
                return cache[i]; // return true only if call suceeds
                                 // call is false, nothing happens. keep iterating
                                 // prevents early stopping like in index 2
                }
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
*/