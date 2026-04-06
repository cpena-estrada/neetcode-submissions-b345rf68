class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        //.   l.       m.       h
        while(low<=high){
            int mid = (low+high) / 2;

            if(nums[mid] == target){
                return mid;
            }

            if(nums[mid] < target){
                low = mid+1;
            }else{ //nums[mid] > target
                high = mid-1;
            }
        }

        return -1;
    }
};
