class Solution {
public:

    bool is_alphanumeric(char c) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;

        while (i < j) {
            // check if i its NOT alphanumeric
            if (!is_alphanumeric(s[i])) {
                i++;
                continue;
            }
            //check if j is alphanumberic
            if (!is_alphanumeric(s[j])) {
                j--;
                continue;
            }
            //check if not equal 
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            // dont forget to advance!!!!!!
            i++;
            j--;
        }
        return true;
    }
};


/*

        int i = 0;
        int j = s.length()-1;

        while(i<j){
            if( !( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))){
                i++;
                continue;
            }

            if( !( (s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= '0' && s[j] <= '9'))){
                j--;
                continue;
            }

            if( std::tolower(static_cast<char>(s[i])) != tolower(static_cast<char>(s[j])) ){
                return false;
            }
            i++;
            j--;
        }
        return true;

*/