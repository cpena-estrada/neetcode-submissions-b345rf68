class Solution {
public: 

    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& used, vector<int>& path) {
        // if path is size of original array (permutations are equal to size of orignal array)
        // if path has all numbers
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) { continue; }

            used[i] = 1; //mark as used
            path.push_back(nums[i]); // append to path

            backtrack(nums, result, used, path);

            used[i] = 0;
            path.pop_back();
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> used(nums.size(), 0);
        vector<int> path;

        backtrack(nums, result, used, path);
        
        return result;
    }
};

/*
                  /          \
                1              []
            /       \
        1,2           1
        /  \          / \
    1,2,3   1,2     1,3   1
                    /  \
               1,3,2  1,3

base cases:
path.size() = nums.size() { retrun } 
i => nums.size()

*/
