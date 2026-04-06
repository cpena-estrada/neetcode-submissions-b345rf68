class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> result(size, -1);

        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if(temperatures[j] > temperatures[i]) {
                    result[i] = j - i; 
                    break;
                }
            }
            if (result[i] == -1) {
                result[i] = 0;
            }
        }
        result[size-1] = 0;
        return result;
    }
};


/* 

for i = 0; i < temp.size - 1 i++ 
    for int j = i+1 <temp.size; j++
        if [j] < [i] {
            result.push_back(j-i)
        }
    }
    if [i] == -1 pushback(0)


*/