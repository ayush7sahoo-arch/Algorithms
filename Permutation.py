def func(n):
    return (n*(n-1)//2)+1

t=int(input())
ans=[]
for i in range(t):
    n=int(input())
    ans.append(func(n))

for i in ans:
    print(i)