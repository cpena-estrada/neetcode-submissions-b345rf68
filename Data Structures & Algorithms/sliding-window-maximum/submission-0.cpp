class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;

        for (int i = 0; i <= nums.size() - k; i++) {
            int window_max = INT_MIN;
            for (int j = i; j < k + i; j++) { // keep ofset in mind
                window_max = max(window_max, nums[j]);
            }
            res.push_back(window_max);
        }
        return res;
    }
};

/*

starting from left = 0, right = 0

keep track of max num

if (i - j + 1 == k) {
    if max value index falls within i and j keep it, else reset it
    move left (loopincrement right)
}

prev_max = {INT_MIN, -1}

curr_max = 8

l
    r
1,2,8,0,4,2,6

    l
        r
1,2,8,0,4,2,6

int curr_max = INT_MIN + 1;
for (int right = 0; right < nums.size(); i++) {
    curr_max = max(nums[right]);

    // if window size  == k
    if (right - left + 1 == k){
        int candidate;

        if (prev_max.second >= left && prev_max <= right) {
            candidate = max(prev_max.first, curr_max)
        } else {
            prev_max = {curr_max, right}; // 
            candidate = curr_max;
        }

        res.push_back(candidate);

        curr_max = INT_MIN + 1; //reset
        left++;


    }
}
*/