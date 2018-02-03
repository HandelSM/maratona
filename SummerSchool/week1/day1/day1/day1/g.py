n, k = map(int, raw_input().split())

fac = [1]
for x in xrange(1, 101):
    fac.append(x * fac[-1])

resp = []
nFac = fac[n-1]
globSt = 1
globNd = fac[n]
while len(resp) != n:
    st = globSt
    nd = st + fac[n - len(resp) - 1]
    divisoria = (nd - st)/n
    print(st, nd, divisoria)
    for elem in xrange(0, n):
        print(st + elem*divisoria)
        print(st + (elem+1)*divisoria)
        if k >= st + elem*divisoria and k <= st + (elem+1)*divisoria:
            globSt = st + elem*divisoria
            globNd = globSt + divisoria
            resp.append(elem+1)
            break

for k in resp:
    print(k),


