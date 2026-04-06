class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> res;

        for (const auto& word : strs) {
            string sorted_word = word;

            sort(sorted_word.begin(), sorted_word.end());

            if (map.count(sorted_word)) {
                map[sorted_word].push_back(word);
            } else {
                map[sorted_word] = {word};
            }
        }

        for (const auto& [_, anagrams] : map) {
            res.push_back(anagrams);
        }
        return res;
    }
};

/*

map where key is sorted word/key -> [words with same letters (anagrams)]

*/