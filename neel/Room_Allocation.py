import sys, heapq

input = sys.stdin.readline
t = int(input())
intervals = [None] * t
for i in range(t):
    a, b = map(int, input().split())
    intervals[i] = (a, b, i)

intervals.sort()

heap = []
room_count = 0
ans = [0] * t

for i in range(t):
    a, b, idx = intervals[i]
    if heap and heap[0][0] < a:
        end_time, room_id = heapq.heappop(heap)
    else:
        room_count += 1
        room_id = room_count
    ans[idx] = room_id
    heapq.heappush(heap, (b, room_id))

sys.stdout.write(str(room_count) + "\n")
sys.stdout.write(" ".join(map(str, ans)))