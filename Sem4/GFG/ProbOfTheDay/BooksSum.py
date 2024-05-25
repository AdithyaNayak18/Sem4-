"Goal is that When an input array with size of books is given, to return the max sum of consequetive book sizes
def max_Books(self, n, k, arr):
    res = 0
    cnt = 0
    for i in range(len(arr)):
        if arr[i] <= k:
            cnt += arr[i]
        else:
            cnt = 0
        res = max(res, cnt)
    return res
