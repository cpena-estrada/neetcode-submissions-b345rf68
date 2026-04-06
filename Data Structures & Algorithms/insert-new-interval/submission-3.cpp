class Solution {
public:

//Two intervals [a, b] and [c, d] overlap if and only if:
//c <= b && a <= d

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> return_vec;
        int size = intervals.size();

        //push back any intevals that dont overlap with newInterval
        int i = 0;
        while(i < size && intervals[i][1] < newInterval[0]){
            return_vec.push_back(intervals[i]);
            i++;
        }

        //handle and push back any overlaps
        // 1---3  4---6
        //   2-----5
        while(i<size && intervals[i][0] <= newInterval[1]){
            if(intervals[i][0] < newInterval[0]){
                newInterval[0] = intervals[i][0];
            }

            if(intervals[i][1] > newInterval[1]){
                newInterval[1] = intervals[i][1];
            }

            i++;
        }

        //now you should be able to push new interval
        return_vec.push_back(newInterval);

        //push back remaining intervals
        while(i<size){
            return_vec.push_back(intervals[i]);
            i++;
        }

        return return_vec;
    }
};

        //new interval is larger than all intervals
        // - look at intervals[size-1][0] and see if its smaller than newInterval[0];
        // - if it is, pushback from newInterval (a vector) to intervals (a vector of vectords)
        // - return intervals

        //new interval is smaller than all intervals
        // - same logic as above but flipped 

//solution
/*

        int size = intervals.size();
        vector<vector<int>> return_vector;

        //BASE CASES:
        //new interval is empty (aka no new interval given)
        if(newInterval.empty()){
            return intervals;
        }
        //the opposite
        if(intervals.empty()){
            return_vector.push_back(newInterval);
            return return_vector;
        }

        /*new interval is larger than all intervals
        if(intervals[size-1][1] < newInterval[0]){
            intervals.push_back(newInterval);
            return intervals;
        }

        //new interval is smaller than all intervals
        if(intervals[0][0] > newInterval[1]){
            intervals.insert(intervals.begin(), newInterval);
            return intervals; 
        }

        //1. add all intervals before newInterval
        int i=0;
        while(i < size && intervals[i][1] < newInterval[0]){
            return_vector.push_back(intervals[i]);
            i++;
        }

        //2. merge all intervals overlapping with newInterval (skiped for nice insert cases [example 2)
        //think line segments: 1-----3  4----6
        //                         2-------5
        //                          1<2 , so they are overlapping
        //                   min(1,2)        max(3,5)
        // uodated newInterval: 1-----5
        while(i < size && intervals[i][0] <= newInterval[1]){ //&& intervals[i][1] >= newInterval[0]
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
        }

        //3. after merging, push the newInterval
        return_vector.push_back(newInterval);

        //4. push the rest of the intervals (if any)
        while(i<size){
            return_vector.push_back(intervals[i]);
            i++;
        }

        return return_vector;
        */