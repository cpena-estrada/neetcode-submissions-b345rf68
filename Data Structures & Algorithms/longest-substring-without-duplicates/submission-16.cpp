class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) { return 0; }

        unordered_set<char> set;
        int best_len = 1; // at least 1 char in string
        int left = 0, right = 0;

        while (right < s.length()) {
            if (set.count(s[right])) {
                set.erase(s[left]);
                left++;
            } else {
                set.insert(s[right]);
                int len = (right - left) + 1;
                best_len = max(best_len, len);
                right++;
            }
        }
        return best_len;
    }
};

/*

longest subtr withouth DUPLICATE characters

    duplicate -> think set

    if the current character in the set
        erase char at left from set (because it was repeated)
        move left pointer right

    if curr char not in set
        insert into set
        caluclate len (right - left) + 1
        cacl best len
        right++

    


    l
    r
    zxyzxyz







        int size = s.length();
        int count = 0;

        if (size <= 1) return size; 

        unordered_set<char> set;
        int left = 0;
        int right = 0;

        // for (int right = 0; right < s.size(); ++right) 
        while (right < size) {
            if (!set.count(s[right])) {
                set.insert(s[right]);
                count = max(count, (right - left) + 1); // THIS GOT YOU. 
                right++;
            } 
            else { // if right is in the set
                set.erase(s[left]);
                left++;
            } 
        }
        return count;


optimal O(n)

l and r at 0. 
if right aint in the set, r++ (make window longer)
calc max (r-l, count)
while left in the set, l++ (shring the window)




base case: 
    - empty string
    - return 0

    iterate over s
    - always inster i into the set, count ++
        - check if j in the set:
            -compare if temp_count > count
            - reset temp_count and clear the set
            - if it is break 
            
            -else temp_count++ 



1st solution, not elegant. check on each block of if else. placed it outside and
did not realize I was breaking before checking. solved by initializing count to 1; dummy

        int size = s.length();

        if (size == 0) return 0; // if (size <= 1) return size;
        if (size == 1) return 1;

        int count = 1; // since test cases passed, longest substring must be at least 1
        unordered_set<int> set; 
        
        for (int i = 0; i < size; ++i) {
            set.insert(s[i]);               // COULD JUST CLEAR THE SET FOR EACH I/BEGINNING OF SUBSTRING
            int best = 1;
            for (int j = i+1; j < size; ++j) {
                if (set.count(s[j])) { // If its in the set
                    set.clear();
                    break;
                } else {               // If its NOT in the set
                    best++;
                    set.insert(s[j]);
                    count = max(count, best);
                }
            }
        }
        return count;
    }
*/
