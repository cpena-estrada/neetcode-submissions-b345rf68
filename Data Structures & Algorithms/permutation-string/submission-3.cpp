class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) { return false; }

        unordered_map<char, int> freq_s1; // char, frequency
        unordered_map<char, int> freq_s2; // char, frequency | updated live
        int window_len = s1.size();

        // populate freqs for s1
        for (const auto& c : s1) { freq_s1[c]++; }

        // populate freq for s2 with the frist s1.size() characters of s2
        for (int i = 0; i < window_len; i++) { freq_s2[s2[i]]++; }
    
        if (freq_s1 == freq_s2) { return true; } // check that initial window frequency

        int left = 0;
        freq_s2[s2[left]]--;
        if (freq_s2[s2[left]] == 0) { freq_s2.erase(s2[left]); } // make sure you do s2[left] and not just left
        left = 1;
        for (int right = window_len; right < s2.size(); right++) {
            freq_s2[s2[right]]++;

            if (freq_s1 == freq_s2) { return true; }

            freq_s2[s2[left]]--;
            if (freq_s2[s2[left]] == 0) { freq_s2.erase(s2[left]); }

            left++; // advance window
        }
        return false;
    }
};

/*

s2 CANNOT BE SHORTER THAN s1

    if it is, it cannot be a permutation!

      l r
    lecabee


SLIDING WINDOW (two maps): 

freq map for just s1

sliding window + freq map to keep count of chars in window

if at any moment the maps are equal, we found a permutation

    original:

    class Solution {
    public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> freq_s1; // char, frequency
        unordered_map<char, int> freq_s2; // char, frequency | updated live

        // populate freqs for s1
        for (const auto& c : s1) { freq_s1[c]++; }

        // populate freq for s2 with the frist s1.size() characters of s2
        for (int i = 0; i < s1.size(); i++) { freq_s2[s2[i]]++; }

        if (freq_s1 == freq_s2) { return true; }

        int left = 0, right = s1.size() - 1;

        while (right < s2.size()) { 
            right++;
            if (right < s2.size()) { freq_s2[s2[right]]++; } //NASTY BOUNDS check because poor organization
            freq_s2[s2[left]]--;

            if (freq_s2[s2[left]] == 0) { freq_s2.erase(s2[left]); }

            left++;

            if (freq_s1 == freq_s2) { return true; }
        }
        return false;
    }



brute force idea:

sort s1

get every possible substring in s2
    sort each and heck if any equal to s1

l
le
lec
leca
lecabe
lecabee

e
ec
eca
ecab
ecabe
ecabee

and so on

substr tirkcery:

if i did .substr(i,j), it wouldnt get the last character of the full worf
    id get lecabe instead of lecabee

    i and j are positions ( (j - i) is distance formuala)

    if you want count of items in a range its j-i+1

BRUTE FORCE:

       string s1_sorted = s1;
        sort(s1_sorted.begin(), s1_sorted.end());

        // generate every possible substring of s2
        for (int i = 0; i < s2.size(); i++) {
            for (int j = i; j < s2.size(); j++) {
                string substr = s2.substr(i, (j - i + 1) ); // use for a window [i..j] (inclusive) (count of items im a range)
                cout << substr << endl;
                sort(substr.begin(), substr.end());
                if (substr == s1_sorted) { return true;}
            }
        }
        return false;

original burte force idea

    bool checkInclusion(string s1, string s2) {
        string s1_sorted = s1;
        sort(s1_sorted.begin(), s1_sorted.end());

        // generate every possible substring of s2
        for (int i = 0; i < s2.size(); i++) {
            string substr = "";
            for (int j = i; j < s2.size(); j++) {
                substr += s2[j];

                string temp = substr;
                sort(temp.begin(), temp.end());
                if (s1_sorted == temp) { return true; }
            }
        }
        return false;
    }
*/