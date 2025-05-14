#Remove duplicates
n=int(input('Enter the limit : '))
a=[]
b=[]
for i in range(n):
    a.append(int(input('Enter the %sth number : '%(i+1))))
print(a)
for i in a:
    if i not in b:
        b.append(i)
print('The list after removing duplicates is',b)
