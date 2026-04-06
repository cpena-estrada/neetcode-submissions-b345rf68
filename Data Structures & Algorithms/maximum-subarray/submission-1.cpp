class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best_sum = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                best_sum = max(best_sum, sum);
            }
        }
        return best_sum;
    }
};

/*

brute force:

int best_sum = nums[0];

for (int i = 0; i < nums.size()) {
    int sum = 0;
    for (int j = i; j < nums.size(); j++) {
        sum += nums[j];
    }
    best_sum = max(best_sum, sum);
}

return sum;

*/