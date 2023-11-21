import sys

N = int(input())
stack = []

for i in range(N):
    command = list(sys.stdin.readline().split())
    
    if command[0] == "push_front":
        stack.insert(0, command[1])
    elif command[0] == "push_back":
        stack.append(command[1])
    elif command[0] == "pop_front":
        if len(stack) == 0:
            print(-1)
        else:
            print(stack.pop(0))
    elif command[0] == "pop_back":
        if len(stack) == 0:
            print(-1)
        else:   
            print(stack.pop(-1))
    elif command[0] == "size":
        print(len(stack))
    elif command[0] == "empty":
        if len(stack) == 0:
            print(1)
        else:
            print(0)
    elif command[0] == "front":
        if len(stack) == 0:
            print(-1)
        else:
            print(stack[0])
    elif command[0] == "back":
        if len(stack) == 0:
            print(-1)
        else:
            print(stack[-1])