class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.length();

        if (size == 0) return 0;
        if (size == 1) return 1;

        int count = 0;
        unordered_set<int> set; 
        
        for (int i = 0; i < size; ++i) {
            set.insert(s[i]);
            int temp_count = 1;
            for (int j = i+1; j < size; ++j) {
                if (!set.count(s[j])) { // if not in the set
                    set.insert(s[j]);
                    temp_count++;
                } else {                // in the set
                    if (temp_count > count) {
                    count = temp_count; // count
                    }
                    temp_count = 0; // reset for next window (i iteration)
                    set.clear();    
                    break;
                }
                if (temp_count > count) {
                    count = temp_count; // count
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
*/