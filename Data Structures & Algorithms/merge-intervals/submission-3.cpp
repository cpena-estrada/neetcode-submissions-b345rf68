class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret_vec;
        //sort them because easier
        sort(intervals.begin(), intervals.end());
        
        vector<int> current = intervals[0];

        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] <= current[1]){
                current[0] = (min(intervals[i][0], current[0]));
                current[1] = (max(intervals[i][1], current[1]));
            }else{ // if they dont overlap
                ret_vec.push_back(current);
                current = intervals[i];
            }
        }
        //look at base test case 2
        //you might end and have not finihsed pushing the last one
        ret_vec.push_back(current);

        return ret_vec;
    }
};

        //   2--4
        // 1-2
        //-------
        //   1   2
        // 1---3
        //    2---6