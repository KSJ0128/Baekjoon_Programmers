N, K = map(int, input().split())
coin, cnt, index = [0]*N, 0, 0

for i in range(N-1, -1, -1): # 제대로 수행
    coin[i] = int(input())
while True: 
    if coin[index] <= K:
        cnt += K // coin[index]
        K = K % coin[index] 
        if K == 0:
            print(cnt)
            break
    index += 1