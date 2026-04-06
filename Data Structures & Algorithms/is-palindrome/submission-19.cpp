class Solution {
public:
    bool isPalindrome(string s) {
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

            if( std::tolower(static_cast<unsigned char>(s[i])) != tolower(static_cast<unsigned char>(s[j])) ){
                return false;
            }
            i++;
            j--;
        }
        return true;


        
        /*while(i<j){
            if(!( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))){
                i++;
                //continue;
            }else{
                if(!( (s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= '0' && s[j] <= '9'))){
                    j--;
                    //continue;
                }else{
                    if(std::tolower(static_cast<unsigned char>(s[i])) != std::tolower(static_cast<unsigned char>(s[j])) ){
                        return false;
                    }else{
                        i++;
                        j--;
                    }
                }
            }
        }
        return true; */
    }
};
