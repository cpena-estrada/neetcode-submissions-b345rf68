class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        string s1_sorted = s1;
        sort(s1_sorted.begin(), s1_sorted.end());

        // generate every possible substring of s2
        for (int i = 0; i < s2.size(); i++) {
            for (int j = i; j < s2.size(); j++) {
                string substr = s2.substr(i, j - i + 1);
                cout << substr << endl;
                sort(substr.begin(), substr.end());
                if (substr == s1_sorted) { return true;}
            }
        }
        return false;
    }
};

/*

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