class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.size() == 1) { return nums[0]; }

        // nums.size() >= 2
        int left = 0;
        int right = nums.size() - 1;

        int ans = INT_MAX;
        while (left <= right) {
            int mid = (left + right) / 2;

            ans = min(ans, nums[mid]);

            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

/*
       l m r
[3,4,5,6,1,2]

     l
     r     
[4,5,0,1,2,3]

l   m   r
3 4 5 1 2

      m  
      l r
3 4 5 1 2


l
m r
2,1

if at any moment, your [left] is < [right]
    you are in a sorted portion. return [left]


if your [mid] > [right]
    move right
else [mid] < [right]
    move left




*/