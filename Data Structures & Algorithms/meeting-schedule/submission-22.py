"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        """
        return false if an overlap is detected
        """
        # base case, 1 or less meetings
        if not intervals:
            return True

        intervals.sort(key= lambda x: x.start) # sort by start
        reference = intervals[0]

        for interval in intervals[1:]:
            if interval.start < reference.end:
                # overlap
                return False
            reference = interval # update reference as you go

        return True


"""
a ----- b           reference, sorted by start time (so it comes first)
    c ----- d
"""