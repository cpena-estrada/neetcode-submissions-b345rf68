class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        res = []
        n = len(intervals)
        intervals.sort(key= lambda x: x[0]) # sort by start time asc
        
        new_interval = intervals[0]
        i = 1
        while i < n:

            if intervals[i][0] <= new_interval[1]:
                # overlaps
                new_interval[0] = min(new_interval[0], intervals[i][0])
                new_interval[1] = max(new_interval[1], intervals[i][1])
            else:
                # non-overlapping
                res.append(new_interval)
                new_interval = intervals[i]

            i += 1

        res.append(new_interval)
        
        return res

"""
set of intervals

return as list of lists, with overlapping intervals merged


a ------- b     new_interval
     c -------d
"""