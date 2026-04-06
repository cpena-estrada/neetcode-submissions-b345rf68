class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best_sum = nums[0];
        int curr_sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (curr_sum < 0){ 
                curr_sum = 0;
            }
            curr_sum += nums[i];
            best_sum = max(best_sum, curr_sum);
        }
        return best_sum;
    }
};

/*

kadanes algo:

if you add a negative to a negative, you get an even more negative number

so if your current sum goes negative, just reset it




dp:

let dp[i] the max possible running sum at index i

    at each index ask yourself whats better, 
        continue running sum dp[i-1] + nums[i]
    or start a new running sum at nums[i] because nums[i] > running sum at that moment 

chatgpt intepratiation:
	•	Define dp[i] = max subarray sum that ends at index i.
	•	Recurrence: dp[i] = max(nums[i], dp[i-1] + nums[i]).
	•	Answer is max(dp), because the optimal subarray must end somewhere.



    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
        }

        return *max_element(dp.begin(), dp.end());
    }



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