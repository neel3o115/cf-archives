from heapq import heappush, heappop
t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    s = input()
    pen = []

    for i in range(k):
        temp = input()
        pen.append(temp)
    
    c2p = dict()

    pq0 = []
    pq1 = []

    for i in range(n):
        pass

    for i in range(k):
        ip = pen[i]
        for c in ip:
            if c in c2p:
                c2p[c].append(i+1)
            else: 
                c2p[c] = [i+1]
    
    for i in c2p[s[0]]:
        heappush(pq0, [1, [i]])

    for i in range(1, n):
        vis = [0]*(k+1)

        if i%2 == 1:
            while len(pq0) != 0:
                x = pq0[0][0]
                y = pq0[0][1][-1]
                for ipen in c2p[s[i]]:
                    if y == ipen:
                        if len(pq1) == 0:
                            vis[ipen] = x
                            heappush(pq1, [x, pq0[0][1]+[ipen]])
                        else:
                            if pq1[0][0] > x:
                                vis[ipen] = x
                                heappop(pq1)
                                heappush(pq1, [x, pq0[0][1]+[ipen]])
                    else:
                        if vis[ipen] == 0:
                            vis[ipen] = x+1
                            heappush(pq1, [x+1, pq0[0][1]+[ipen]])
                        else:
                            if vis[ipen] > x+1:
                                heappop(pq1)
                                heappush(pq1, [x+1, pq0[0][1]+[ipen]])

                heappop(pq0)

        else:
            while len(pq1) != 0:
                x = pq1[0][0]
                y = pq1[0][1][-1]
                for ipen in c2p[s[i]]:
                    if y == ipen:
                        if len(pq0) == 0:
                            vis[ipen] = x
                            heappush(pq0, [x, pq1[0][1]+[ipen]])
                        else:
                            if pq0[0][0] > x:
                                vis[ipen] = x
                                heappop(pq0)
                                heappush(pq0, [x, pq1[0][1]+[ipen]])
                    else:
                        if vis[ipen] == 0:
                            vis[ipen] = x+1
                            heappush(pq0, [x+1, pq1[0][1]+[ipen]])
                        else:
                            if vis[ipen] > x+1:
                                heappop(pq0)
                                heappush(pq0, [x+1, pq1[0][1]+[ipen]])
                    
                heappop(pq1)        

    if n%2 == 1:
        print(*pq0[0][1])
    else:
        print(*pq1[0][1])