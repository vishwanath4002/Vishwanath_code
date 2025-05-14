#Reverse without creating a new list
n=int(input('Enter the limit : '))
a=[]
for i in range(n):
    a.append(int(input('Enter the element : ')))
print(a)
for i in range(n//2):
    a[i],a[-1-i]=a[-1-i],a[i]
print(a)
