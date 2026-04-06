#include <unordered_map>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        vector<pair<int,int>> freq_list;
        vector<int> ans; 

        for(int i=0; i<nums.size(); i++){
            if(map.find(nums[i]) != map.end()){
                map[nums[i]]++;
            }else{
                map[nums[i]] = 1;
            }
        }

        for(const auto& pair : map){
            //make_pair is needed as push_back takes in only one arguement
            //second is the frequency
            //first is the value
            freq_list.push_back(std::make_pair(pair.second, pair.first));
        }

        //so now freq_list is a vector in which each index the pairs are
        // <frequency, value>
        // frequencies are not sorted/organized

        //when sorting pairs, by default, it sorts based on the first element of pair
        //we use greater to sort in descending order 
        std::sort(freq_list.begin(), freq_list.end(), greater<pair <int,int> >());

        //iterate from the back of the freq_list k times,
        //as the larger frequencies will be there

        for(int i=0; i<k; i++){
            ans.push_back(freq_list[i].second);
        }

        //doing this didn't work as cases when k > than freq_list.size() it would go out of bounds
        /*for(int i=freq_list.size()-1; i>=freq_list.size()-k; i--){
            ans.push_back(freq_list[i].second);
        }*/

        return ans;
    }
};
