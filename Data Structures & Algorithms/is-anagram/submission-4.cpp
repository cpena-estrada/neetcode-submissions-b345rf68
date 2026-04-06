#include <unordered_map>
class Solution {
public:
    bool isAnagram(string s, string t){

        if(s.length() != t.length()){
            return false;
        }
        unordered_map<char,int> s_map;
        unordered_map<char, int> t_map;

        //populate s_map with chars from s string
        for(int i=0; i<s.length(); i++){
            if(s_map.find(s[i]) != s_map.end()){
                s_map[s[i]]++;
            }else{
                s_map[s[i]];
            }
        }

        //populate t_map with chars from t string
        for(int i=0; i<t.length(); i++){
            if(t_map.find(t[i]) != t_map.end()){
                t_map[t[i]]++;
            }else{
                t_map[t[i]];
            }
        }

        //check if both maps are equal
        if(s_map == t_map){
            return true;
        }else{
            return false;
        }
    }
};