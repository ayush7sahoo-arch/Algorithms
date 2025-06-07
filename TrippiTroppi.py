t=int(input())
ans=[]
for i in range(t):
    s=input()
    temp=""
    for j in s.split():
        temp+=j[0]
    ans.append(temp)
for i in ans:
    print(i)