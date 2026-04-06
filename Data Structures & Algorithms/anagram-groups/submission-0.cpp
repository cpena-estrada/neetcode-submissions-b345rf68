#include <unordered_map>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //sort the stirngs from the vectors that was passed in
        //create a map
        //key would be the sorted string (set of characters)
        //value would be the string/word from the original vecotr 

        unordered_map < string, vector<string> > map;
        vector<vector<string>> return_vector;  

        for(int i=0; i<strs.size(); i++){
            //std::sort(strs[i].begin(), strs[i].end()); works but i would make my value also be the sorted version of thr stirng/ incorrect

            std::string sorted = strs[i];

            std::sort(sorted.begin(), sorted.end());

            //check if alrady in the map
            //if it is, append the new value to the vector in the value of the key

            if(map.find(sorted) != map.end()){
                map[sorted].push_back(strs[i]); 
                //map.find(sorted)->second.push_back(strs[i]); //assumes the key exists, if it doesn't ERROR!
            }else{
                map[sorted] = {strs[i]};
                //map.insert(pair<string, vector<string> (map[sorted], strs[i]));
            }
        }

        //iterate through map and return the value vectors
        for(const auto &pair : map){
            return_vector.push_back(pair.second);
        }

        return return_vector;
    }
};
