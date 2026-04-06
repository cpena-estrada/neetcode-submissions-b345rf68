class Solution {
public:

    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) { return mid;}

            // left sorted segment
            if (nums[left] <= nums[mid]) { 
                // target in [left, mid)?
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // right sorted segment
            else if (nums[mid] <= nums[right]) {
                // target in (mid, right]?
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};


/*

if [mid] > target && [mid] > [right]
    move right

 l r
 m
[1,3], target 3

 l     m   r
[3,4,5,6,1,2]

 l m r
[3,5,1], target 3

 l m r
[3,1,2]

*/