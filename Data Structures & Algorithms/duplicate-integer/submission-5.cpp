class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (const auto& num : nums) {
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }
        
        return false;
    }
};

/*

        unordered_set<int> set;

        for(int i=0; i<nums.size(); i++){
            if(set.find(nums[i]) != set.end()){
                return true;
            }else{
                set.insert(nums[i]);
            }
        }
        return false;

*/