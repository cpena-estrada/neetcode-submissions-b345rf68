class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;

        int temp = 1;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums.size(); j++){
                if(j != i){
                    temp *= nums[j];
                }
            }
            answer.push_back(temp);
            temp = 1;
        }
        return answer;
    }
};
