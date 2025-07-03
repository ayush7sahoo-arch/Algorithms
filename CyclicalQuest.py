
s=input()
n=int(input())
for _ in range(n):
    c=input()
    ch=c+c
    ans=0
    for i in range(len(s)-len(c)+1):
        temp=s[i:i+len(c)]
        if(ch.__contains__(temp)):
            ans+=1
        

    print(ans)
