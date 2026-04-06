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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a.start < b.start;
        });

        for (int i = 0; i < intervals.size(); ++i) {
            Interval a = intervals[i];
            for (int j = i + 1; j< intervals.size(); ++j) {
                Interval b = intervals[j];
                // check for overlapness
                if (b.start < a.end) {
                    return false;
                }
            }
        }

        // for (const auto& interval : intervals) { 
        //     cout << interval.start << " " << interval.end << " \n\n ";
        // }

        return true;
    }
};

/*
overlapping (if sorted by start time):
    a & b

    b.start > a.start & b.end < a. end

brute force would be to check every unique pair of meetings for ovelapness




*/