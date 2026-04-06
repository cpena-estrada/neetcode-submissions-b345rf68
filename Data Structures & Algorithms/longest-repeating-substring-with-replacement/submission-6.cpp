class Solution {
public:

    int get_max_freq(unordered_map<char, int>& freqs) {
        int best = 0;
        for (const auto& [_, freq] : freqs) {
            best = max(best, freq);
        }
        return best;
    }

    int characterReplacement(string s, int k) {
        unordered_map<char, int> freqs; 
        int left = 0, right = 0, best_len = 0;

        while (right < s.length()) {
            freqs[s[right]]++; // increment freq as you go with RIGHT pointer
            int window_len = (right - left) + 1;
            int max_freq = get_max_freq(freqs);

            if ((window_len - max_freq) <= k) {
                best_len = max(best_len, window_len);
            } else {
                freqs[s[left]]--; // decrement freq as you go with LEFT pointer
                left++;
            }
            right++;
        }
        return best_len;
    }
};
/*

the condition to solve the problem:

in a given window size
    you want to replace the characters with the least frequency
    

    how do you find how many replacements you can make

    window length - freq of char making up most of the window

    if that number is < k, increase the window size (move right pointer right)

    else make it smaller (move left pointer right)

    increment and decrement frequencies as you go




original attempt (dont work):


dont wokr because i fix the first character

BAAA, k = 1

my code compares b to a and changes a -> BBAA

but solution is AAAA

        int best_len = 0;

        for (int i = 0; i < s.length(); i++) {
            int replacements = 0;
            for (int j = i; j < s.length(); j++) {
                if (s[i] == s[j]) {
                    int len = (j - i) + 1;
                    best_len = max(best_len, len);
                }
                else if (s[i] != s[j] && replacements < k) {
                    replacements++;
                    int len = (j - i) + 1;
                    best_len = max(best_len, len);
                }
                if (replacements > k) { break; }
            }
        }
        return best_len;
*/

