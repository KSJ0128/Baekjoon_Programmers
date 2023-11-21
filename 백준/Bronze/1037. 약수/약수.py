cnt = int(input())

if cnt == 1: # 약수 한 개인 경우
    divisor = int(input())
    print(divisor*divisor)
else:   
    divisor = list(map(int, input().split()))
    for i in range(cnt):
        for j in range(i+1, cnt):
            if divisor[i] > divisor[j]:
                divisor[i], divisor[j] = divisor[j], divisor[i]
    print(divisor[0]*divisor[cnt-1])