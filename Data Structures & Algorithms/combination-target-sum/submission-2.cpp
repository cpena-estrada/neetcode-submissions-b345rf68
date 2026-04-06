// could get away with passing a total variable by value through the dfs func
// for picking:
// just pass total + nums[i] 
// not picking:
// just pass total

class Solution {
public:

    vector<vector<int>> result;
    vector<int> option_sum;

    void dfs_backtrack(int i, int total, int target, vector<int>& nums) {
        if (total == target) { 
            result.push_back(option_sum);
            return;                       // dont keep going as sums are bigger and youd get duplcates on the no pick path
        }
        
        if (i >= nums.size() || total > target) { return; }

        // pick
        option_sum.push_back(nums[i]);
        dfs_backtrack(i, total + nums[i], target, nums);

        // not pick
        option_sum.pop_back();
        dfs_backtrack(i + 1, total, target, nums); // no total + 1 because we didnt "pick" it so we didnt add it
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs_backtrack(0, 0, target, nums);
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

    visual:

                      2
                /           \
               [2]            [] 
              /    \
          [2,2]     [2,5]
          /  \
    [2,2,2]  [2,2,5]    THIS IS WHY WE HAVE TO RETURN IF WE FOUND ONE. we explore not picked with the same total/option_sum
              /    \
      [2,2,5,5]    2,2,
    coded psudo code^ with a set for duplicates and sum function instead of running total variable

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

        // if option sum == target and option sum is has not been seen
        if (sum(option_sum) == target && !the_set.count(option_sum)) {        ////RETURN HERE TO AVPID DUPES AND NO SET NEEDED
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

*/