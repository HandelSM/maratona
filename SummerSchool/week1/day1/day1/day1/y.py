fid = [0,1,1]

for x in xrange(3, 1001):
    fid.append(fid[x-1] + fid[x-3])

k = int(raw_input())
print(fid[k])
