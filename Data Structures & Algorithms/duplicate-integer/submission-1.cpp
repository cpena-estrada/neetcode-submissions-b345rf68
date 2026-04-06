#include <unordered_map>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        //unordered_map<int,int> the_map;
        unordered_set<int> the_map;

        for(int i=0; i<nums.size(); i++){
            if(the_map.find(nums[i]) != the_map.end()){
                return true;
            }else{
                //the_map.insert(pair<int,int> (nums[i],nums[i]));
                the_map.insert(nums[i]);
            }
        }

        return false;
    }
};
