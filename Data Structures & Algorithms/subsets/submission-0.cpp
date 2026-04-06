// draw it out. only way i understood it. 
class Solution {
public:

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
*/
