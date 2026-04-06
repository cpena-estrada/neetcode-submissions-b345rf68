class Solution {
public:
    int lengthOfLongestSubstring(string s) {
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
};

/*

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


*/
