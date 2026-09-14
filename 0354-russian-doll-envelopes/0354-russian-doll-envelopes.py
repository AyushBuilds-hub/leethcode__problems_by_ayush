import bisect

class Solution:
    def maxEnvelopes(self, envelopes: list[list[int]]) -> int:
        if not envelopes:
            return 0
        
        # Sort by width ascending, then height descending
        envelopes.sort(key=lambda x: (x[0], -x[1]))
        
        # Extract heights and find LIS using patience sorting / binary search
        tails = []
        for w, h in envelopes:
            idx = bisect.bisect_left(tails, h)
            if idx < len(tails):
                tails[idx] = h
            else:
                tails.append(h)
        
        return len(tails)