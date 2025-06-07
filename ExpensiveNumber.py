t=int(input())
ans=[]
for i in range(t):
    n=input()
    Tzero=0
    for j in range(len(n)-1,0,-1):
        if(n[j]=='0'):
            Tzero+=1
        else:break
    nonZeros=0
    for j in n:
        if(j!='0'):
            nonZeros+=1
    tot=Tzero+nonZeros-1
    ans.append(tot)
for temp in ans:
    print(temp)