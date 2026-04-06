class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map; // num : frequency of num
        vector<int> res;

        for (const auto& num : nums) { map[num]++; }

        vector<pair<int, int>> num_freq(map.begin(), map.end());

        // sort by frequency in decreasing order
        sort(num_freq.begin(), num_freq.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        for (int i = 0; i < k; i++) {
            res.push_back(num_freq[i].first);
        }

        return res;
    }
};

/*

get the freqeuncies of each number

*/