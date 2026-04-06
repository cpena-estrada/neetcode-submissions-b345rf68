#include <unordered_map>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        //make a frequency map
        //put numbers an frequencies into a vector of pairs
        //somehow sort them in decreasing orddr
        //return a vector with values with the highest freq

        unordered_map<int,int> freq_map; // ( number , frequency ) 
        vector<pair<int,int>> pairs; // ( frequency , number)
        vector<int> return_vector;

        //populate frequency map
        for(int i = 0; i < nums.size(); i++){
            if(freq_map.find(nums[i]) != freq_map.end()){
                freq_map[nums[i]]++;
            }else{
                freq_map[nums[i]] = 1; //important to set to one as default is 0
            }
        }

        //iterate over frequancy map and place pairs into pair vector
        //  -make_pair is needed as push_back() takes in only one arguementi

        for(const auto &pair : freq_map){
            pairs.push_back(make_pair(pair.second, pair.first));
        }

        //sort (increasing order)
        sort(pairs.begin(), pairs.end());

        for(int i=0; i<k; i++){
            int num = pairs.back().second;
            return_vector.push_back(num);
            pairs.pop_back();
        }

        return return_vector;




        /*
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
        //we use greater<>() to sort in descending order 
        std::sort(freq_list.begin(), freq_list.end(), greater<pair <int,int> >());

        //iterate from the back of the freq_list k times,
        //as the larger frequencies will be there

        for(int i=0; i<k; i++){
            ans.push_back(freq_list[i].second);
        }

        //doing this didn't work as cases when k > than freq_list.size() it would go out of bounds
        /*for(int i=freq_list.size()-1; i>=freq_list.size()-k; i--){
            ans.push_back(freq_list[i].second);
        }

        return ans;*/
    }
};
