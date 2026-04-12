t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    
    total_sum = 0.0     # Sum of all subarray averages
    count = 0           # Total number of subarrays

    # Iterate over all subarrays [l, r]
    for l in range(n):
        cur_sum = 0
        for r in range(l, n):
            cur_sum += a[r]
            sub_avg = cur_sum / (r - l + 1)
            total_sum += sub_avg
            count += 1

    ans = total_sum / count
    print(ans)
