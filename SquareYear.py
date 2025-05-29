import math


t=int(input())
ans=[]
for i in range(t):
    year=int(input())
    c=int(math.sqrt(year))
    appended=False
    if(c**2==year):
        for k in range(c//2+1):
            j=c-k
            if ((k+j)**2==year):
                ans.append([k,j])
                appended = True
                break
                
            
    if(appended==False):
        ans.append([-1])
    
for i in range (t):
    for j in ans[i]:
        print(j,end=" ")
    print()
    