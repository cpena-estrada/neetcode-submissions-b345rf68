#include <unordered_map>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        /* 
        get the frequencies of each element
            - make a freq map of num : freq

        sort by frequency in decreasing order
            - harder/intuative way:
                - make vector of pairs
                - build pairs as <freq, num>
                - sort
                - get first k from the end
            - cooler way
                - copy the map into a vec of pairs in one line
                - sort by second using lambda
                - get first k easily 
        
        return the top k nums 
        */

        unordered_map<int,int> num_freq_map; 

        //build freq map
        for(int i=0; i<nums.size(); i++){
            if(num_freq_map.find(nums[i]) != num_freq_map.end()){
                num_freq_map[nums[i]]++;
            }else{
                num_freq_map[nums[i]] = 1;
            }
        }

        vector<pair<int,int>> num_freq_vec(num_freq_map.begin(), num_freq_map.end());

        /*for(int i=0; i<num_freq_vec.size(); i++){
            cout << num_freq_vec[i].first << " " << num_freq_vec[i].second << " ";
        }*/
        /*
        for(auto& pairs : num_freq_vec){
            cout << pairs.first << " " << pairs.second << " ";
        }
        */
        for(auto& [num, freq] : num_freq_vec){
            cout << num << " " << freq << " ";
        }

        sort(num_freq_vec.begin(), num_freq_vec.end(), [](auto& a, auto& b) {
            return a.second > b.second;
        });

        vector<int> ret_vec;

        /*
        for(int i=0; i<k; i++){
            ret_vec.push_back(num_freq_vec[i].first);
        }
        */
        int i=0;
        for(auto& [num, freq] : num_freq_vec){
            if (i == k){    //if(ret_vec == k) {break} As soon as ret_vec has k elements, you stop iterating.
                break;
            }
            i++;

            ret_vec.push_back(num);
            
        }

        return ret_vec;
    

    }
};

        /*
        //make a frequency map
        //put numbers an frequencies into a vector of pairs
        //somehow sort them in decreasing orddr
        //return a vector with values with the highest c

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
            return_vector.push_back(num);    //or int num = pairs[pairs.size() - 1].second;
            pairs.pop_back();
        }

        return return_vector; */




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