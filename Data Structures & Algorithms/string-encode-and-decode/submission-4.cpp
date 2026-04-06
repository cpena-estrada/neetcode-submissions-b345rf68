class Solution {
public:

    string encode(vector<string>& strs) {
        string answer = "";
        for(int i=0; i<strs.size(); i++){
            answer += std::to_string(strs[i].length());
            answer += "#";
            answer += strs[i];
            
        }
        return answer;
    }

    vector<string> decode(string s) {
        vector<string> answer;

        int i=0;
        while(i<s.length()){ //read the number up to # (because it can be a double digit)
            string word = "";
            string s_num = "";
            while(s[i] != '#'){
                s_num += s[i];
                i++;
            }

            int sub_size = stoi(s_num); //turn it into an int

            i++; //to move past the '3'
            for(int j=0; j<sub_size; j++){ //read the acual word
                word += s[i];
                i++; //move it over to the beggining of the next number
            }

            answer.push_back(word);
        }


        return answer;
    }
};
