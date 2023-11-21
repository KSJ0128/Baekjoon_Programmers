sum, sub = map(int, input().split())
# a+b, a-b
if sum < sub:
    print(-1)
elif (sum+sub)%2 != 0 or (sum-sub)%2 != 0:
    print(-1)
else:
    print((sum+sub)//2, (sum-sub)//2)