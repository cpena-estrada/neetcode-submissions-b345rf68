class Solution {
public:

    void dfs_backtrack(int i, vector<int>& subset, vector<int>& nums, vector<vector<int>>& result) {
        if (i >= nums.size()) {
            result.push_back(subset);
            return;
        }

        // pick it and explore all options
        subset.push_back(nums[i]);
        dfs_backtrack(i + 1, subset, nums, result);
    
        //dont pick it and explore for a DIFFERENT number
        subset.pop_back();
        while (i + 1 < nums.size() && nums[i+1] == nums[i]) {
            i++;
        }

        dfs_backtrack(i + 1, subset, nums, result);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // nums size == 1 
        sort(nums.begin(), nums.end());
        vector<int> subset;
        vector<vector<int>> result;
        dfs_backtrack(0, subset, nums, result);
        return result;
    }
};

/*

              /                 \
             1                  [] 
            /   \               /   \
        1,2      1             2        []
       / \       / \          /\        /\
 1,2,1  1,2    1,1  1       2,1  2     1  []
                           dupl      dupl

all subsets on this side
will have a 2                   so whe picking two again here you get duplicate

            7       []      
          /   \     / \
        7,7   7    7   []    


        1,1,2

after picking the first 1
you can pick next 1 because we are at the same recursion level
or dont pick it

                1                                            []  
            /       \     skip all 1's                      /   \  
          1,1        1 dont pick 2nd 1       skip all 1's  2.    []
          /  \       /  \
       1,1,2  1,1   1,2  1
                   



random thought for for loop approach:

        // do a aingle recursive call because we want to always pass i,
        // not calling i+1 to move forward. so for loop

        for (int i = 0; i < nums.size(); i ++) {
            //
        }
*/