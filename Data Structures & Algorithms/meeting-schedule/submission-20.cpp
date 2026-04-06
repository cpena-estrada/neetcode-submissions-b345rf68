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
    //    5----10
    // 0----------30
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a.start < b.start;
        });

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i-1].end > intervals[i].start) {
                return false;
            }
        }
        return true;
    }
};

/*
overlapping (if sorted by start time):
    a & b

    b.start < a.end

overlapping (not sorted) (LOOK AT THEM ACROSS)

    a.start < b.end AND b.start < a.end

    or fancier

    min(a.end, b.end) > max(a.start, b.start)


 a   1-----5
 b       4----7

 a       4-----7
 b     1----5

  a       4-----7
 b          5--6


brute force would be to check every unique pair of meetings for ovelapness (not sorted)

        if (intervals.empty() || intervals.size() == 1) { return true; }

        for (int i = 0; i < intervals.size() - 1; ++i) {
            Interval a = intervals[i];
            for (int j = i + 1; j < intervals.size(); ++j) {
                Interval b = intervals[j];
                // check for overlapness
                if (b.start < a.end && a.start < b.end) {
                    return false;
                }
            }
        }
        return true;
    }


//
sorted:
    more verbose because i check looking forwards (start at 0 look at i+1)
    instead of checking backwards (start at 1 look at i-1)


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



*/