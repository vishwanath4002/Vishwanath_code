a=[]
b=[]
n=int(input('Enter the limit : '))
print('Enter %s strings.'%n)
for i in range(n):
    a.append(input())
for i in a:
    b.append(i[1::])
print('The new list is',b)
