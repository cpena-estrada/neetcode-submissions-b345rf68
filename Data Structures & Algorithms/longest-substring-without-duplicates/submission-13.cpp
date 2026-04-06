class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.length();
        int count = 0;

        if (size <= 1) return size; 

        unordered_set<int> set;
        int left = 0;
        int right = 0;

        while (right < size && left < size) {
            if (!set.count(s[right])) {
                set.insert(s[right]);
                count = max(count, (right - left) + 1);
                right++;
            } 
            else { // if right is in the set
                set.erase(s[left]);
                left++;
            } 
        }
        return count;
    }
};

/*

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
