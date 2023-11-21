a = list(input())
a.sort(reverse = True)
str = ""
for i in range(len(a)):
    str += a[i]
print(str)