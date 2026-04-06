class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());

        for (int i = 0; i <= nums.size(); ++i) {
            if (!set.count(i)) {
                return i;
            }
        }
        return -1;
    }
};

/*

make a frequency map up to size n
then check fir first instance of 0

*/