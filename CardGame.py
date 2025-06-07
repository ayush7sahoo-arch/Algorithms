t=int(input())
for i in range(t):
    n=int(input())
    card=input()
    if(card[0]==card[-1]):
        if(card[0]=="A"):
            print("Alice")
            continue
        else:
            print("Bob")
            continue

    if(card.index("A")==n-1):
        print("Bob")
        continue
    if(card.index("B")==n-1):
        print("Alice")
        continue
    
    if(card[-1]==card[-2]):
        if(card[-1]=="A"):
            print("Alice")
            continue
        else:
            print("Bob")
            continue

    print("Bob")