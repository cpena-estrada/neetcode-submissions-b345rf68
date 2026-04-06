#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;

        for(int i=0; i<nums.size(); i++){
            int diff = (target - nums[i]);

            if(map.find(diff) != map.end()){
                return {map[diff], i};
            }else{
                map[nums[i]] = i;
                //map.insert(pair<int,int> (nums[i] = i));
            }
        }

        return {};

        //iterate through nums
        //find the difference between target and nums[i]

        //check if nums[difference] is in the map
            //if it is, retun current index and /////
        //else
            //put nums[i], i
    }
};

// key        value
//  nums[i]   i

//target 6

// | 3 | 3 |