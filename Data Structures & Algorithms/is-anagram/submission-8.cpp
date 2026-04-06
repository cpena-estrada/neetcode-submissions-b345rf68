class Solution {
public:
    bool isAnagram(string s, string t) {
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

array of size 26 


*/