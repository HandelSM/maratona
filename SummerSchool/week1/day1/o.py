def gcd(a, b):
    if b > 0:
        return gcd(b, a % b)
    return a

def lcm(a,b):
    return a * b / gcd(a,b)

n = int(raw_input())
ans = 1
for k in xrange(1, n+1):
    ans = lcm(ans, k)

print(ans)
