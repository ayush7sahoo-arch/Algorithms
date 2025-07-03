t=int(input())
for _ in range(t):
    n=int(input())
    print(2*n-1)
    for i in range(1,n+1):
        print(i,1,i)
        if(i!=n):
            print(i,i+1,n)