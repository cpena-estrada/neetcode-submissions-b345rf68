class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret_vec;
        //sort them because easier
        sort(intervals.begin(), intervals.end());
        
        vector<int> merged = intervals[0]; //keep on updating this one until no overlap, then push it

        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] <= merged[1]){
                merged[0] = (min(intervals[i][0], merged[0]));
                merged[1] = (max(intervals[i][1], merged[1]));
            }else{ // if they dont overlap
                ret_vec.push_back(merged);
                merged = intervals[i];
            }
        }
        //look at base test case 2
        //you might end and have not finihsed pushing the last one
        ret_vec.push_back(merged);

        return ret_vec;
    }
};

        //   2--4
        // 1-2
        //-------
        //   1   2
        // 1---3
        //    2---6