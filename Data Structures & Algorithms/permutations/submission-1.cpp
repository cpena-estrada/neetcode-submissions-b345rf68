// arrays/lists are updated accordingly for each call
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
            if (used[i]) { continue; } // if the num at index i has been used in the curr path,
                                       // skip it/dont explore
            used[i] = 1; //mark as used
            path.push_back(nums[i]); // append to path

            backtrack(nums, result, used, path); // explore to fill next slot with numbers not used

            // undo to try another number
            used[i] = 0;
            path.pop_back();
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> used(nums.size(), 0); // to track which num has been used
        vector<int> path;

        backtrack(nums, result, used, path);
        
        return result;
    }
};

/*
dont think of it as a tree
                  /          \
                1              []
            /       \
        1,2           1
        /  \          / \
    1,2,3   1,2     1,3   1
                    /  \
               1,3,2  1,3

instead:

Recursion = depth
Each recursive call represents: “I’m filling the next slot in the permutation.”
First call → filling slot 0
Second call → filling slot 1
…
Base case → all slots filled
So recursion is like going down levels of a tree, one slot at a time.

For loop = breadth
At each slot, you don’t have just one choice. You can place any unused number there.
At slot 0, you can pick 1, or 2, or 3.
At slot 1 (after picking 1 first), you can pick 2 or 3.
…
That “pick among many options” is exactly what the for loop does.
So the loop is like branching sideways in the tree: every iteration is a different choice at the same depth.

*/
