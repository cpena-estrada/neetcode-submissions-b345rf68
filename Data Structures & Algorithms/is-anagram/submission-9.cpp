class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq;

        for (const auto& c : s) {
            freq[c]++;
        }

        for (const auto& c : t) {
            freq[c]--;
        }

        for (const auto& pair : freq) {
            if (pair.second != 0) { return false; }
        }

        return true;
    }
};

/*
sorting:
        if (s.length() != t.length()) {
            return false;
        }
        
        sort(s.begin(),s.end());
        sort(t.begin(), t.end());

        if (s == t) { return true; }
        return false;

array of size 26: 
        vector <int> alphabet(26, 0);

        for (const auto& c : s) {
            alphabet[c - 'a']++;
        }
                                    // if anagrams, should cancel out, leaving alphabet 0
        for (const auto& c : t) {
            alphabet[c - 'a']--;
        }

        for (const auto& c : alphabet) {
            if (c != 0) { return false; }
        }
        return true;

*/