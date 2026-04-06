/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        // if (intervals.empty()) { return 0; }
        // if (intervals.size() = 1) { return 1; }
        if (intervals.size() <= 1) { return intervals.size(); }

        // make arrays of star and end times
        vector<int> start, end;
        for (const auto& interval : intervals) {
            start.push_back(interval.start);
            end.push_back(interval.end);
        }

        // sort star and end times
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int s = 0;
        int e = 0;
        int rooms = 0;

        // if the earliest start is less than the earliest end, you need a room
        // else, you dont

        int count = 0;
        while (s < intervals.size()) {
            if (start[s] < end[e]) {
                count++;
                s++;
            } else {
                count--;
                e++;
            }
            rooms = max(rooms, count);
        }
        return rooms;
    }
};

/*

0------------------------40 
   5----10                     
                 15---20     


start = [0, 5, 15]
end = [10, 20, 40]



*/