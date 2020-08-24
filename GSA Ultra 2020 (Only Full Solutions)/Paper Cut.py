"""
this problem can be solved using some math. 
"""

import math
m = 1000000007
def solution(qs):
    mylist = []
    for i in range(len(qs)):
        (a, b, c, d) = qs[i]
        q = math.gcd(math.gcd(a,b), math.gcd(c,d))
        a //= q
        b //= q
        c //= q
        d //= q
        k = math.gcd(a, b)
        if(((c * d) % (a * b)) != 0):
            continue
        if(c % a == 0 and c % b == 0): 
            #can we represent d as a sum of some multiples of a and b?
            if(d % k != 0):
                continue
            elif(d % k == 0 and d > (a * b // k - a - b)):
                mylist.append(i)
            else:
                while(d >= 0):
                    if(d % b == 0):
                        mylist.append(i)
                        break
                    d -= a
        elif(d % a == 0 and d % b == 0):
            k = math.gcd(a, b)
            if(c % k != 0):
                continue
            elif(c % k == 0 and c > (a * b // k - a - b)):
                mylist.append(i)
            else:
                while(c >= 0):
                    if(c % b == 0):
                        mylist.append(i)
                        break
                    c -= a
        elif ((c % a == 0 and d % b == 0) or (c % b == 0 and d % a == 0)):
            mylist.append(i)
    def modpow(base, exp):
        ans = 1
        while(exp >= 1):
            if(exp % 2 == 1):
                ans *= base
            base *= base
            exp //= 2
        return ans
    final = 0
    for i in range(len(mylist)):
        final += modpow(2, mylist[i])
    return final % m