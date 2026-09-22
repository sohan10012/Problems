class Solution:
    def eraseOverlapIntervals(self, intervals: list[list[int]]) -> int:

        intervals.sort(key=lambda x: x[1])

        pe = intervals[0][1]
        re = 0

        for i in range(1,len(intervals)):

            start = intervals[i][0]
            end = intervals[i][1]

            if start < pe:
                re += 1
            else:
                pe = end

        return re        

