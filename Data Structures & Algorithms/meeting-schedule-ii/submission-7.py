"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        """
        min number of days/rooms to host all meetings
        """
        start_times = sorted([i.start for i in intervals])
        end_times = sorted([i.end for i in intervals])

        max_rooms = 0
        curr_rooms = 0
        s = e = 0
        while s < len(intervals):
            if start_times[s] < end_times[e]: 
                # meeting statrs beofre a meeting ends
                curr_rooms += 1
                max_rooms = max(max_rooms, curr_rooms)
                s += 1
            else:
                curr_rooms -= 1
                e += 1

        return max_rooms



"""
at any point in time, how many meetings are currently running. 
A meeting is running if it has started but not ended yet.


start times: [0, 5, 15]
end_times:   [10, 20, 40] 

if a meeting starts before a meeting as ended, you need a room

if a meeting starts after a meeting has eneded, you dont need an extra room

0 ----------------------- 40
   5 ---- 10
                15 ---- 20      


init approach:

flaw — one reference interval can't track which rooms have freed up.
You need to track ALL currently active meetings, not just the longest one.

       if not intervals:
            return 0 # no rooms needed
        
        intervals.sort(key= lambda x: x.start) # sort by start time
        reference = intervals[0]
        max_overlaps = 0 # we dont have enough meeting rooms, add an extra day

        count = 0
        for interval in intervals[1:]:
            if interval.start < reference.end:
                # overlaps
                count += 1
                reference = max(reference, interval, key= lambda x: x.end) # keep the one that ends later (more likely to overlap, what we are checking)
            else:
                max_overlaps = max(max_overlaps, count)
                count = 0

        if count != 0:
            max_overlaps = max(max_overlaps, count)

        return max_overlaps
"""