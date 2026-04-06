class Solution {
public:

    string longestPalindrome(string s) {
        string res = "";
        int len = s.length();
        if (len <= 1) { return s; }

        int max_len = 0;
        int max_start_idx = 0;

        for (int i = 0; i < len; i++) {
            //odd len palindorme 
            int l = i, r = i;
            while(l >= 0 && r < len && s[l] == s[r]) {
                l--; r++;
            }

            int sub_len = (r-1) - (l+1) + 1;
            if (sub_len > max_len) {
                max_len = sub_len;
                max_start_idx = l + 1;
            }

            //even len palindrome
            l = i;
            r = i + 1;
            while(l >= 0 && r < len && s[l] == s[r]) {
                l--; r++;
            }
            sub_len = (r-1) - (l+1) + 1;
            if (sub_len > max_len) {
                max_len = sub_len;
                max_start_idx = l + 1;
            }
        }
        return s.substr(max_start_idx, max_len);
    }
};

/*

two pointers. one at beg one at end
if not palindormic, move pointer inwards
    - but what pointer to move?

    nope

super burte force:
    for every possibe pair (nested for loop, i = 0, j = i+1)
        - check if palindrome
            - track mac len


expanding outward solution:

    palindormes mirror around center
        Odd length (e.g., "aba"): center is a character -> (i, i)
        Even length (e.g., "abba"): center is between characters -> (i, i+1)

    so try all centers


    ababd

    odd palindorme
    i=0:  
           
            
    i=1: 
          l
          r
          b

        expand

        l   r
        a b a 

        expand
      l       r
        a b a
      0 1 2 3 4

        len of palindrome is (r-1) - (l+1) + 1
          

    even palindrome:


    
    
*/
