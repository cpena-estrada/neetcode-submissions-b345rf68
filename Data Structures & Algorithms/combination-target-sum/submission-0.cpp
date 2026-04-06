class Solution {
public:

    //globals
    vector<vector<int>> result;
    vector<int> option_sum;
    set<vector<int>> the_set; 

    int sum(vector<int>& arr) {
        int total = 0;
        for (const auto& num : arr) { total += num; }
        return total;
    }

    void dfs_backtrack(int i, vector<int>& nums, int target) {
        if (i >= nums.size() || sum(option_sum) > target) { return; }

        if (sum(option_sum) == target && !the_set.count(option_sum)) { 
            result.push_back(option_sum);
            the_set.insert(option_sum);      // add to set so no repeats!!!
        }

        // pick option and explore
        option_sum.push_back(nums[i]);
        dfs_backtrack(i, nums, target);

        // dont pick it and explore
        option_sum.pop_back();
        dfs_backtrack(i+1, nums, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        if (nums.size() == 0) { return {}; }

        dfs_backtrack(0, nums, target);
        return result;
    }
};

/*

    dfs(int i, nums, target) {
        if reached the end of nums or sum > target {  return so we stop exploring }

        if numbers in option sum add up to target {
            push it result
            result.push_back(option_sum)
        }

        //pick current number
        option_sum.push_back(nums[i]);
        // explore path
        dfs(i, nums, target)

        // dont pick it
        option_sum.pop_back()
        explore path
        dfs(i+1, nums, target)

    }


                       2
                /           \
               [2]            [] 
              /    \
          [2,2]     [2,5]
          /  \
    [2,2,2]  [2,2,5]



*/