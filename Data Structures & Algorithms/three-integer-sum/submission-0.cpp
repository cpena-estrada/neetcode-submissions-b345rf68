class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        set<vector<int>> seen_triplets; 

        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = i + 1; j < nums.size() - 1; j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] + nums [j] + nums [k] == 0) {
                        // check if not seen
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        sort(triplet.begin(), triplet.end());
                        if (!seen_triplets.count(triplet)) {
                            answer.push_back(triplet);
                            seen_triplets.insert(triplet);
                        }
                    }
                }
            }
        }
        return answer;
    }
};

/*

[-4,-1,-1,0,1,2]

*/