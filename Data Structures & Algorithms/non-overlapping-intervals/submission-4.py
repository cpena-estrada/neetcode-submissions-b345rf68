class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if len(intervals) == 1: return 0

        intervals.sort(key= lambda x: x[0]) # sort by end time ascedning

        #intervals.sort(key= lambda x: x[1]) # sort by end time ascedning

        print(intervals)

        n = len(intervals)
        count = 0 # to count of many intervals were removed
        prev_interval = intervals[0]

        for i in range(1, n):
            
            if prev_interval[0] < intervals[i][1] and prev_interval[1] > intervals[i][0]: # if it overlaps, "remove" the longer one
                prev_interval = min(prev_interval, intervals[i], key= lambda x: x[1]) # keep the one with earlier end
                count += 1
            else:
                prev_interval = intervals[i] # doesn't overlap

        return count
        



"""
when intervals are sorted by end time, it overlaps if
    start < prev_end

When two intervals overlap, KEEP the one that ends earlier.

Because the earlier it ends, the more room it leaves for future intervals
-> it minimizes future conflicts.


1--2      
   2---4
1---------4   



here interval check break because when we pick the interval with the later end,
it could pick

        if len(intervals) == 1: return 0

        intervals.sort(key= lambda x: x[1]) # sort by end time ascedning

        print(intervals)

        n = len(intervals)
        count = 0 # to count of many intervals were removed
        prev_interval = intervals[0]

        for i in range(1, n):
            
            if prev_interval[0] < intervals[i][1]: # if it overlaps, "remove" the longer one
                prev_interval = min(prev_interval, intervals[i], key= lambda x: x[1]) # keep the one with earlier end
                count += 1
            else:
                curr_interval = intervals[i] # doesn't overlap

        return count





"""