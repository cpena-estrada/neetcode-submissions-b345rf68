class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::unordered_set<int> set;

        for (const auto& num : nums) {
            if (set.count(num)) {
                return num;
            } else {
                set.insert(num);
            }
        }
        return -1;
    }
};
