def bitCounter(n):
    c=0
    while(n>0):
        c+=n&1
        n=n>>1
    return c


t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    even=0
    bits=0
    for i in a:
        bits+=bitCounter(i)
        if(i%2==0):
            even+=1
    if(even>=k):
        print(bits+k)
    else:
        for i in range(len(a)):
            if(a[i]&1==0):
                a[i]+=1
                bits+=1
                k-=1
        j=1
        while(k>0):
            for i in a:
                # if(k==0):
                #     break
                # if(k<0):
                #     bits-=1
                #     break
                
                if(i&(1<<j)==0 ):
                    if(k>=(1<<j)):
                        bits+=1
                        k-=(1<<j)
                    else:
                        k=-1
                        break
                
            j+=1
        print(bits)




        
