lottery = [int(x) for x in input().split()]
n = int(input())
for i in range(n):
    t = [int(x) for x in input().split()]
    if(len(list(set(lottery) & set(t)))>=3):
        print("Lucky")
    else:
        print("Unlucky")
