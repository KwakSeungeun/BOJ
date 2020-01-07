# https://www.acmicpc.net/problem/1463

import queue

num = int(input())
dp = [0]*(num+1)

q = queue.Queue()
q.put(num)

while q.empty() == False:
    cur = q.get()
    cnt = dp[cur]
    # -1 연산
    if cur > 1:
        if dp[cur-1]==0 or dp[cur-1] > cnt + 1 : #적은 횟수를 가진 것만 넣기
                q.put(cur-1)
                dp[cur-1] = cnt + 1
    
    # /3 /2 연산 (둘 다 모두 해봐야 알 수 있음)
    for i in range(2,4):
        if cur%i == 0:
            if dp[int(cur/i)]==0 or dp[int(cur/i)] > cnt + 1 : #적은 횟수를 가진 것만 넣기
                q.put(int(cur/i))
                dp[int(cur/i)] = cnt + 1

print(dp[1])    
