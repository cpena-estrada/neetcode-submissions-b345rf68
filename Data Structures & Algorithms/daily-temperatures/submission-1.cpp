class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> res(size, 0);
        stack<pair<int,int>> s;

        s.push(make_pair(temperatures[0], 0)); // temp, idx

        for (int i = 0; i < size; ++i) {
            while (!s.empty() && temperatures[i] > s.top().first) {
                res[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push(make_pair(temperatures[i], i));
        }

        return res;
    }
};


/* 

   21
   22         [22,21,30]
 stack

make result vector of temperatures.size() init all to 0's

if size = 1 ret res 

declare stack of paris <int temp, int idx>

push temperaturs[0]

for loop at i = 1 to temp.size
    while( !s.empty() && temp[i] > s.top().first ) {
        res[s.top.second] = i - s.top.second
        s.pop()
    }
    else {
        s.push(make_pair(temp[i], i))
    }



for i = 0; i < temp.size - 1 i++ 
    for int j = i+1 <temp.size; j++
        if [j] < [i] {
            result.push_back(j-i)
        }
    }
    if [i] == -1 pushback(0)


my solution:
        int size = temperatures.size();
        vector<int> result(size, -1); // initialize to all -1's

        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) { // iterate over all possible pairs
                if(temperatures[j] > temperatures[i]) { // first instance of higher temp
                    result[i] = j - i; // calc how many days passed and place result in return vec
                    break; // make sure to stop looking after the first instance 
                }
            }
            if (result[i] == -1) { //if no hotter day was found (result wasnt updated)
                result[i] = 0; //mark it w zero
            }
        }
        result[size-1] = 0; // the last day recorded does not have any future days to compare it, so it will always be 0
        return result;   


*/