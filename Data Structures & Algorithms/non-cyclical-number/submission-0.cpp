class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> the_set; // to keep track of seen calculations

        string num_string = to_string(n);
        // cout << num_string << "\n";
        int total = 0;

        while (true) {
            for (int i = 0; i < num_string.size(); ++i) {
                int num = num_string[i] - '0'; // get cur digit char to int
                num = num * num; //square it
                total += num; // keept track of sum
            }

            if (total == 1) { return true; }
            if (the_set.count(total)) { return false;} 

            the_set.insert(total);
            num_string = to_string(total);
            total = 0; // reset it for next iter. do it here because you need to have total declared prior to loop start
        }
        return false; // just to aovid warning
    }
};

/*

num_string = turn it into a string

while(!the_set.count(total))

    get length of num_string

    for each single number
        type cast to integer
        square it
        add to total variable

    if total = 1, return true
    
    insert total into set
    turn total into string
    num_string = total

return false;
*/