class Solution {
public:

    // freq map of substr has at same frequency of chars in t
    bool is_valid (string t, unordered_map<char, int>& s_freq, unordered_map<char, int>& t_freq) {
        for (const auto& c : t) {
            // if key doesnt exist or exists but freq count is < freq count in t
            if (!s_freq.count(c) || s_freq[c] < t_freq[c]) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        if (s.size() < t.size()) { return ""; }

        unordered_map<char, int> t_freq;

        for (const auto& c : t) { t_freq[c]++; }

        int best_len = INT_MAX; 
        int start = -1, take; // use these to extract the substr to return. -1 as a flag val in case it doesnt update

        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> s_freq;
            for (int j = i; j < s.size(); j++) {
                s_freq[s[j]]++;
                if (is_valid(t, s_freq, t_freq)) {
                    int len = j - i + 1;
                    if (len < best_len) { 
                        start = i;
                        take = len;
                        best_len = len;
                    }
                }
            }
        }
        if (start == -1) { return ""; }
        return s.substr(start, take);
    }
};

/*

BRUTE FORCE (nasty way to keep track of len and string to retrun. instead, keep track of indeces^):

    // freq map of substr has at same frequency of chars in t
    bool is_valid (string t, unordered_map<char, int>& s_freq, unordered_map<char, int>& t_freq) {
        for (const auto& c : t) {
            // if key doesnt exist or exists but freq count is < freq count in t
            if (!s_freq.count(c) || s_freq[c] < t_freq[c]) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        if (s.size() < t.size()) { return ""; }

        unordered_map<char, int> t_freq;

        for (const auto& c : t) { t_freq[c]++; }

        pair<string, int> res("", INT_MAX); // substr, its len

        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> s_freq;
            int j = i;
            while (j < s.size()) {
                s_freq[s[j]]++;
                if (is_valid(t, s_freq, t_freq)) {
                    string substr = s.substr(i, j - i + 1);
                    if (substr.size() < res.second) {
                    res.first = substr;
                    res.second = substr.size();
                    }
                }
                j++; // advance j
            }
        }
        return res.first;
    }
};
    generate every possible substring

    if frequeny of that substr has frequencies >= to that of the chars in t
        its a valid candidate.

    helper func to check if substr valid:

        for each char in t:
            if s_freq[c] >= t_freq[c]
                its a valid substr
                
                keep track on min candiadte seen so far

    psudocode

    freq map for t

    for (int i = 0; i < s.size(); i++) {
        unordered_map<char, int> s_freq;
        for (int j = i; j < s.size(); j++) {
            build frequency of the substr
        }
        check if substr is a valid candiddate with funciton above
    }
    
    XYJFJFJDJDFJDJZ

    lowercase?
        XY____z 

    char lower(cahr c) {
        if c >= 'A' && c <= 'Z'
            retrun c - 
    }
*/