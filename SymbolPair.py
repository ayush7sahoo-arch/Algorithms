s=input()
dict = {}
for i in range(len(s)):
    if(s[i] in dict):
        dict[s[i]] += 1
    else:
        dict[s[i]] = 1

count=0
for key in dict:
    count+=dict[key]**2

print(count)