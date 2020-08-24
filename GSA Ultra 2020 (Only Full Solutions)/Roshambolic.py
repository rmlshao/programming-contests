"""
Simulating the game suffices to get all test cases, but not the bonus for being the fastest.
"""
def solution(a, b):
    beats = {'R': 'S', 'P': 'R', 'S': 'P'}
    count = 0
    while(len(a) > 0 and len(b) > 0):
        count += 1
        play_a, play_b = a[-1], b[-1]
        if(a[-1] == b[-1]):
            a = play_a + a[:-1]
            b = play_b + b[:-1]
        elif(play_b == beats[play_a]):
            a = play_a + play_b + a[:-1]
            b = b[:-1]
        else:
            a = a[:-1]
            b = play_b + play_a + b[:-1]
    return count
