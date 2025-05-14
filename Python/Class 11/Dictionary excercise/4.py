#4
d={}
s=input('Enter the string : ')
for i in s:
    if i.isalnum():
        d[i]=s.count(i)
print(d)
    
