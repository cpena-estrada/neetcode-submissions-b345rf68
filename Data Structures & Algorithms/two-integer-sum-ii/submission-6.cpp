class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                return {left+1, right+1};
            }
            else if (sum < target) {
                left++;
                //continue;
            }
            else if (sum > target) {
                right--;
                //continue;
            }
        }
        return {};
    }
};

/*
ITS SORTED! TAKE ADVANTAGE

have pointer at left , one a right

DOESNT WORK. number on right might be greater than target,
 but when added to left (a negative number) it could add up to target

        while (left < right) {
            if (numbers[right] >= target) {
                right--;
                continue;
            }
            else if ((numbers[right] + numbers[left]) != target) {
                left++;
                continue;
            }
            else if ((numbers[right] + numbers[left]) == target) {
                return {left+1, right+1};
            }
        }
        return {};
    }

Instead, 

while (left < right) {
    if ((numbers[left] + numbers[right]) == target) {
        return {left, right};
    }
    
    if the sum is smaller than target, move left inwards to achieve a bigger sum

    if opposite is true, move right inwards

}

*/


