"""
Segment Trees, plain and simple! 

This scored full marks, but didn't get the bonus for being the fastest solution. Everything from caching the answers into a dict to trying sparse tables out didn't help to improve the constant factor that I assume was limiting the code's speed.
"""

def solution(a, qs):
    n = len(a)
    t = [0] * (2 * n)
    def build():
        for i in range(n):
            t[i + n] = a[i]
        for i in range(n-1, 1, -1):
            t[i] = max(t[(i << 1)],t[(i << 1) | 1])
    def query(l, r): 
        l += n
        r += n
        res = 0
        while(l < r):
            if (l & 1):
                res = max(res, t[l])
                l += 1
            if (r & 1):
                r -= 1
                res = max(res, t[r])
            l >>= 1
            r >>= 1
        return res
    ans = 0
    build()
    for (low, high) in qs:
        ans += query(low, high)
    return ans