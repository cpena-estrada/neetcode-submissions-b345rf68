// draw it out. only way i understood it. 
class Solution {
public:

    vector<vector<int>> result;
    vector<int> subset; // or the path you are taking. gets updated accoringly with push and pop
                        // works because you go all the way left, then you go right

    void dfs_backtrack(int i, vector<int>& nums) {
        // recurse until until i >= num.size()
        if (i >= nums.size()) {
            result.push_back(subset);
            return;
        }

        // pick/include current number and explore that path
        subset.push_back(nums[i]);
        dfs_backtrack(i + 1, nums);

        // don't pick/include it and explore
        // (to act like we didnt pick it, pop it from subset/path)
        subset.pop_back();
        dfs_backtrack(i + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs_backtrack(0, nums);
        return result;
    }
};

/*
think of nums as items in a store. what are all the ways you can walk out
of the store 

you have teo options at each index. 

    pick it 

    dont pick it

input set: [1]

powerset: [], [1]
------------------------
[1,2]

[], [1], [2], [1,2]
------------------------
[1,2,3]

[], [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]
------------------------------------------------




    vector<vector<int>> ret_vec;

    // dfs to explore and backtrack every possibility 

    void dfs(int i, vector<int>& subset, vector<int>& nums) {
        if (i == nums.size()) {
            ret_vec.push_back(subset); // when you reach the last combination possible, append it to result
            return;
        } 
        // pick the current number/item
        subset.push_back(nums[i]); // put it in the bag/ subset
        dfs(i + 1, subset, nums);
        // dont pick it
        subset.pop_back(); // get rid of picked, so now its not picked
        dfs(i + 1, subset, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset; //vec where youll hold the current combination/bag
        dfs(0, subset, nums); // start at index 0
        return ret_vec;
    }
*/
