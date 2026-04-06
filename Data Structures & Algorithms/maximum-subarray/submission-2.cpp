

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums);
        dp[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
        }

        return *max_element(dp.begin(), dp.end());
    }
};

/*

dp:

let dp[i] the max possible running sum at index i

    at each index ask yourself whats better, 
        continue running sum dp[i-1] + nums[i]
    or start a new running sum at nums[i] because nums[i] > running sum at that moment 

brute force O(n^2):

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

sorting (WRONG):
    you cant modify the order of the arr, there is no "subarray" anymore

 sort in decreasing order

 iter iver sorted array
 the moment the sum is less than best sum break
*/