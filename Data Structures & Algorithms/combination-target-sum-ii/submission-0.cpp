/*
lets say target is 8 and there is two 1's
[2, 1, 7, 1, 3, 6]
[1,7] and [7,1] are duplciate combinations

candidates = [1,1,7], target = 8
[1,7] and [1,7]
both satisfy and both would get pushed

you can backtrack this normally and have a set to check for dupes 

or

sort and only process a single 1 rather than all and checking for dupes

thats the trick
*/

class Solution {
public:

    vector<vector<int>> result;
    vector<int> option_sum;
    
    void dfs_backtrack(int i, int total, int target, vector<int>& candidates) {
        if (total == target) {
            result.push_back(option_sum);
            return;            
        }
        
        if (i >= candidates.size() || total > target) { return; }

        option_sum.push_back(candidates[i]);
        dfs_backtrack(i + 1, total + candidates[i], target, candidates);

        // always check if in bounds before accesing
        while(i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
            i++;
        }

        option_sum.pop_back();
        dfs_backtrack(i + 1, total, target, candidates);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs_backtrack(0, 0, target, candidates);
        return result;
    }
};



/*


                
              /                                 \
            9                                   []
         /    \                             /        \                      
        9,2    9                        2          []
    too big                             /             /  \
                                    2,2            2    []
                                    /   \           /  \
                                2,2,4    2,2      2,4    2
                                / \               /  \
                        2,2,4,6   2,2,4      2,4,6   2,4
                                                    /   \
                                                2,4,1    2,4

                          
                        /   \
                     1         []
                    /  \          \
                1,2     1       
                /   \
            1,2,3    1,2,4
            /  \
          too big
*/