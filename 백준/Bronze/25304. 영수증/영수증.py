total_money = int(input())
cnt = int(input())
compare_money = 0

for i in range(cnt):
    data = input().split()
    compare_money += int(data[0]) * int(data[1])
    
if(total_money == compare_money):
    print("Yes")
else:
    print("No")
    