#include <unordered_map>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> set;

        for(int i=0; i<nums.size(); i++){
            if(set.find(nums[i]) != set.end()){
                return true;
            }else{
                //the_map.insert(pair<int,int> (nums[i],nums[i]));
                set.insert(nums[i]);
            }
        }
        return false;
    }
};
