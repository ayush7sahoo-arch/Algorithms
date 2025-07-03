t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    print("1"*k+"0"*(n-k))