# ================== CP TEMPLATE (NEEL) ==================

import sys
input = sys.stdin.readline
from collections import deque
import heapq
from math import gcd, comb

MOD = 10**9 + 7
INF = float('inf')

# ================== MATH ==================

def power(a, b, mod=MOD):
    res = 1
    while b:
        if b & 1:
            res = res * a % mod
        a = a * a % mod
        b >>= 1
    return res

def inv(a): return power(a, MOD-2)

def lcm(a, b): return a*b // gcd(a, b)

# nCr
MAX = 200000
fact = [1]*(MAX+1)
for i in range(1, MAX+1):
    fact[i] = fact[i-1]*i % MOD

inv_fact = [1]*(MAX+1)
inv_fact[MAX] = power(fact[MAX], MOD-2)

for i in range(MAX, 0, -1):
    inv_fact[i-1] = inv_fact[i]*i % MOD

def nCr(n, r):
    if r < 0 or r > n: return 0
    return fact[n]*inv_fact[r]%MOD*inv_fact[n-r]%MOD


# ================== KADANE ==================

def kadane_max(arr):
    cur = arr[0]
    ans = arr[0]
    for i in range(1, len(arr)):
        cur = max(arr[i], cur + arr[i])
        ans = max(ans, cur)
    return ans

def kadane_min(arr):
    cur = arr[0]
    ans = arr[0]
    for i in range(1, len(arr)):
        cur = min(arr[i], cur + arr[i])
        ans = min(ans, cur)
    return ans

def max_circular_subarray(arr):
    total = sum(arr)
    mx = kadane_max(arr)
    mn = kadane_min(arr)
    if mx < 0: return mx
    return max(mx, total - mn)


# ================== PREFIX SUM ==================

def prefix_sum(arr):
    ps = [0]*(len(arr)+1)
    for i in range(len(arr)):
        ps[i+1] = ps[i] + arr[i]
    return ps


# ================== BINARY SEARCH ==================

def binary_search(lo, hi, check):
    while lo < hi:
        mid = (lo + hi) // 2
        if check(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo


# ================== BFS ==================

def bfs(n, adj, start):
    dist = [-1]*n
    q = deque([start])
    dist[start] = 0
    while q:
        u = q.popleft()
        for v in adj[u]:
            if dist[v] == -1:
                dist[v] = dist[u] + 1
                q.append(v)
    return dist


# ================== DFS ==================

def dfs(u, adj, vis):
    vis[u] = True
    for v in adj[u]:
        if not vis[v]:
            dfs(v, adj, vis)


# ================== DIJKSTRA ==================

def dijkstra(n, adj, start):
    dist = [INF]*n
    dist[start] = 0
    pq = [(0, start)]
    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]: continue
        for v, w in adj[u]:
            if dist[v] > d + w:
                dist[v] = d + w
                heapq.heappush(pq, (dist[v], v))
    return dist


# ================== TOPO SORT ==================

def topo_sort(n, adj):
    indeg = [0]*n
    for u in range(n):
        for v in adj[u]:
            indeg[v] += 1

    q = deque([i for i in range(n) if indeg[i] == 0])
    topo = []

    while q:
        u = q.popleft()
        topo.append(u)
        for v in adj[u]:
            indeg[v] -= 1
            if indeg[v] == 0:
                q.append(v)

    return topo if len(topo) == n else []


# ================== BIPARTITE ==================

def is_bipartite(n, adj):
    color = [-1]*n
    for start in range(n):
        if color[start] != -1: continue
        q = deque([start])
        color[start] = 0
        while q:
            u = q.popleft()
            for v in adj[u]:
                if color[v] == -1:
                    color[v] = color[u]^1
                    q.append(v)
                elif color[v] == color[u]:
                    return False
    return True


# ================== DSU ==================

class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1]*n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, a, b):
        a = self.find(a)
        b = self.find(b)
        if a != b:
            if self.size[a] < self.size[b]:
                a, b = b, a
            self.parent[b] = a
            self.size[a] += self.size[b]


# ================== BITMASK ==================

def count_bits(x):
    return bin(x).count('1')


# ================== GRID BFS ==================

dirs = [(1,0),(-1,0),(0,1),(0,-1)]

def bfs_grid(grid, sx, sy):
    n, m = len(grid), len(grid[0])
    vis = [[False]*m for _ in range(n)]
    q = deque([(sx, sy)])
    vis[sx][sy] = True

    while q:
        x, y = q.popleft()
        for dx, dy in dirs:
            nx, ny = x+dx, y+dy
            if 0<=nx<n and 0<=ny<m and not vis[nx][ny]:
                vis[nx][ny] = True
                q.append((nx, ny))


# ================== PARENTHESES ==================

def is_valid_parentheses(s):
    bal = 0
    for ch in s:
        if ch == '(':
            bal += 1
        else:
            bal -= 1
        if bal < 0:
            return False
    return bal == 0


# ================== CATALAN ==================

def catalan(n):
    if n % 2: return 0
    k = n//2
    return comb(2*k, k)//(k+1)


# ================== MILLER RABIN ==================

def is_prime(n):
    if n < 2: return False
    for p in [2,3,5,7,11,13,17,19,23,29]:
        if n % p == 0:
            return n == p

    d, s = n-1, 0
    while d % 2 == 0:
        d//=2
        s+=1

    for a in [2,325,9375,28178,450775,9780504,1795265022]:
        if a % n == 0: continue
        x = pow(a, d, n)
        if x == 1 or x == n-1: continue
        for _ in range(s-1):
            x = (x*x) % n
            if x == n-1: break
        else:
            return False
    return True


# ================== END ==================

def kadane_max(arr):
    max_sum = arr[0]
    cur_sum = arr[0]

    for i in range(1, len(arr)):
        cur_sum = max(arr[i], cur_sum + arr[i])
        max_sum = max(max_sum, cur_sum)

    return max_sum

def kadane_min(arr):
    min_sum = arr[0]
    cur_sum = arr[0]

    for i in range(1, len(arr)):
        cur_sum = min(arr[i], cur_sum + arr[i])
        min_sum = min(min_sum, cur_sum)

    return min_sum

def kadane_with_indices(arr):
    max_sum = float('-inf')
    cur_sum = 0
    start = 0
    l = 0
    r = 0

    for i in range(len(arr)):
        cur_sum += arr[i]

        if cur_sum > max_sum:
            max_sum = cur_sum
            l = start
            r = i

        if cur_sum < 0:
            cur_sum = 0
            start = i + 1

    return max_sum, l, r

def max_circular_subarray(arr):
    total = sum(arr)

    max_kadane = kadane_max(arr)
    min_kadane = kadane_min(arr)

    if max_kadane < 0:
        return max_kadane  # all negative

    return max(max_kadane, total - min_kadane)

def max_subarray_at_least_k(arr, k):
    n = len(arr)

    max_end = [0]*n
    max_end[0] = arr[0]

    for i in range(1, n):
        max_end[i] = max(arr[i], max_end[i-1] + arr[i])

    window_sum = sum(arr[:k])
    ans = window_sum

    for i in range(k, n):
        window_sum += arr[i] - arr[i-k]
        ans = max(ans, window_sum)

        ans = max(ans, window_sum + max_end[i-k])

    return ans

def kadane(arr):
    max_sum = arr[0]
    cur = arr[0]
    for i in range(1, len(arr)):
        cur = max(arr[i], cur + arr[i])
        max_sum = max(max_sum, cur)
    return max_sum

def max_submatrix(matrix):
    n = len(matrix)
    m = len(matrix[0])
    max_sum = float('-inf')

    for left in range(m):
        temp = [0]*n

        for right in range(left, m):
            for i in range(n):
                temp[i] += matrix[i][right]

            max_sum = max(max_sum, kadane(temp))

    return max_sum


def is_valid(s):
    bal = 0
    for ch in s:
        if ch == '(':
            bal += 1
        else:
            bal -= 1
        if bal < 0:
            return False
    return bal == 0

from math import comb

def catalan(n):
    if n % 2: return 0
    k = n // 2
    return comb(2*k, k) // (k + 1)

def generate(n):
    res = []

    def backtrack(s, open_cnt, close_cnt):
        if len(s) == 2*n:
            res.append(s)
            return

        if open_cnt < n:
            backtrack(s + '(', open_cnt + 1, close_cnt)

        if close_cnt < open_cnt:
            backtrack(s + ')', open_cnt, close_cnt + 1)

    backtrack("", 0, 0)
    return res

def min_add_to_make_valid(s):
    bal = 0
    ans = 0

    for ch in s:
        if ch == '(':
            bal += 1
        else:
            if bal > 0:
                bal -= 1
            else:
                ans += 1

    return ans + bal

def min_remove(s):
    stack = []
    remove = set()

    for i, ch in enumerate(s):
        if ch == '(':
            stack.append(i)
        elif ch == ')':
            if stack:
                stack.pop()
            else:
                remove.add(i)

    remove.update(stack)

    res = []
    for i, ch in enumerate(s):
        if i not in remove:
            res.append(ch)

    return ''.join(res)

def longest_valid(s):
    stack = [-1]
    ans = 0

    for i in range(len(s)):
        if s[i] == '(':
            stack.append(i)
        else:
            stack.pop()
            if not stack:
                stack.append(i)
            else:
                ans = max(ans, i - stack[-1])

    return ans

def count_valid_subseq(s):
    n = len(s)
    dp = [0]*(n+1)
    dp[0] = 1

    bal = 0
    for i in range(n):
        if s[i] == '(':
            bal += 1
        else:
            if bal > 0:
                dp[i+1] = dp[i] * bal
                bal -= 1

    return dp[n]




def is_prime(n):
    if n < 2: return False
    for p in [2,3,5,7,11,13,17,19,23,29]:
        if n % p == 0:
            return n == p

    d, s = n-1, 0
    while d % 2 == 0:
        d //= 2
        s += 1

    for a in [2,325,9375,28178,450775,9780504,1795265022]:
        if a % n == 0: continue
        x = pow(a, d, n)
        if x == 1 or x == n-1: continue
        for _ in range(s-1):
            x = (x*x) % n
            if x == n-1: break
        else:
            return False
    return True

from collections import deque

def bfs(n, adj, start):
    dist = [-1] * n
    q = deque()

    q.append(start)
    dist[start] = 0

    while q:
        u = q.popleft()
        for v in adj[u]:
            if dist[v] == -1:
                dist[v] = dist[u] + 1
                q.append(v)

    return dist

def dfs(u, adj, vis):
    vis[u] = True
    for v in adj[u]:
        if not vis[v]:
            dfs(v, adj, vis)

def dfs_iter(start, adj):
    vis = [False] * len(adj)
    stack = [start]

    while stack:
        u = stack.pop()
        if vis[u]: continue
        vis[u] = True

        for v in adj[u]:
            if not vis[v]:
                stack.append(v)

    return vis

import heapq

def dijkstra(n, adj, start):
    dist = [float('inf')] * n
    dist[start] = 0

    pq = [(0, start)]  # (distance, node)

    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]: continue

        for v, w in adj[u]:
            if dist[v] > d + w:
                dist[v] = d + w
                heapq.heappush(pq, (dist[v], v))

    return dist

from collections import deque

def topo_sort_kahn(n, adj):
    indeg = [0] * n

    for u in range(n):
        for v in adj[u]:
            indeg[v] += 1

    q = deque()
    for i in range(n):
        if indeg[i] == 0:
            q.append(i)

    topo = []

    while q:
        u = q.popleft()
        topo.append(u)

        for v in adj[u]:
            indeg[v] -= 1
            if indeg[v] == 0:
                q.append(v)

    if len(topo) != n:
        return []  # cycle exists

    return topo

def topo_sort_dfs(n, adj):
    vis = [0]*n   # 0=unvisited,1=visiting,2=done
    topo = []
    cycle = False

    def dfs(u):
        nonlocal cycle
        vis[u] = 1

        for v in adj[u]:
            if vis[v] == 0:
                dfs(v)
            elif vis[v] == 1:
                cycle = True

        vis[u] = 2
        topo.append(u)

    for i in range(n):
        if vis[i] == 0:
            dfs(i)

    if cycle:
        return []

    return topo[::-1]

from collections import deque

def is_bipartite(n, adj):
    color = [-1] * n   # -1 = uncolored

    for start in range(n):  # handle disconnected graph
        if color[start] != -1:
            continue

        q = deque([start])
        color[start] = 0

        while q:
            u = q.popleft()

            for v in adj[u]:
                if color[v] == -1:
                    color[v] = color[u] ^ 1
                    q.append(v)
                elif color[v] == color[u]:
                    return False

    return True


