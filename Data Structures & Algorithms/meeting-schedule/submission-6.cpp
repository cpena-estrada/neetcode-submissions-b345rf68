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
        if (intervals.size() == 1 || intervals.empty()) { return true; }

        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a.start < b.start;
        });

        // at least of size 2
        for (int i = 0; i < intervals.size() - 1 ; i++) {
            if (intervals[i + 1].start < intervals[i].end) { 
                return false;
            }
        }
        return true;
    }
};

/*
overlapping (if sorted by start time):
    a & b

    b.start => a.start && b.end < a.end // dont work for (0,30) , (0,30)

brute force would be to sort by start and
check every unique pair of meetings for ovelapness

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
        return true;




*/