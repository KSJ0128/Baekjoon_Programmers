N = int(input()) # P의 길이
M = int(input()) # 문자열의 길이
S = input() # 문자열
P = "I"
for i in range(0, N):
    P += "OI"

cnt = 0
for j in range(0, M):
    if(j + 2 * N + 1 > M):
        break
    if(P == S[j:j + 2 * N + 1]):
        cnt += 1
print(cnt)