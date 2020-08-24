"""
The idea is to use dynamic programming, with the states being the list you last took from, the next index in the first list, and the next index in the second list.
Top-down dp is too slow to pass all the cases, but doing it bottom-up works fine! 
"""
def solution(a, b):
    x = len(b)
    y = len(a)
    dp = [[[0 for i in range(x + 1)] for j in range(y + 1)] for k in range(2)]
    dp[1][y][x] = 0
    dp[0][y][x] = 0
    for sum in range(1, y + x):
        if(sum < x):
            lb = 0
        else:
            lb = sum - x
        if(sum > y):
            ub = y + 1
        else:
            ub = sum + 1
        for i in range(lb, ub):
            ref1 = a[y - i - 1]
            ref2 = b[x - (sum - i) - 1]
            if(i == 0):
                dp[0][y - i][x - (sum - i)] = abs(ref1 - b[x - (sum - i)]) + dp[1][y - i][x - (sum - i) + 1]
                dp[1][y - i][x - (sum - i)] = abs(ref2 - b[x - (sum - i)]) + dp[1][y - i][x - (sum - i) + 1]
            elif (i == sum):
                dp[0][y - i][x - (sum - i)] = abs(ref1 - a[y - i]) + dp[0][y - i + 1][x - (sum - i)]
                dp[1][y - i][x - (sum - i)] = abs(ref2 - a[y - i]) + dp[0][y - i + 1][x - (sum - i)]
            else:
                dp[0][y - i][x - (sum - i)] = min(abs(ref1 -  a[y - i]) + dp[0][y - i + 1][x - (sum - i)], abs(ref1 - b[x - (sum - i)]) + dp[1][y - i][x - (sum - i) + 1])
                dp[1][y - i][x - (sum - i)] = min(abs(ref2 -  a[y - i]) + dp[0][y - i + 1][x - (sum - i)], abs(ref2 - b[x - (sum - i)]) + dp[1][y - i][x - (sum - i) + 1])
    return min(a[0] + dp[0][1][0], b[0] + dp[1][0][1])