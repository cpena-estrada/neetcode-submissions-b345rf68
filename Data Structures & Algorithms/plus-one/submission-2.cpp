class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());

        int carry = 1; // initially use as the +1
        bool c = false;

        for (int i = 0; i < digits.size(); i++) {
            int sum = digits[i] + carry;

            if (sum >= 10) {
                digits[i] = 0;
                c = true;
            } else {
                digits[i] = sum;
                carry = 0;
                c = false;
            }
        }
        if (carry) { digits.push_back(1); }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};

/*



naive solution (doesnt work because overflow with stoi):

iterate over digits to build a digit string
convert string to int, add 1, to string, build result vector

        string s_num = "";
        int num;
        vector<int> res;

        for (const auto& digit : digits) {
            s_num += to_string(digit);
        }

        num = stoi(s_num);
        num++;
        s_num = to_string(num);

        for (const auto& digit : s_num) {
            res.push_back(digit - '0');
        }

        return res;
*/