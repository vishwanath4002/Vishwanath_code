#Read n values and store them inside a list
x=[]
n=int(input('Enter the limit : '))
for i in range(n):
    a=int(input('Enter the %sth number : '%(i+1)))
    x.append(a)
print('The list is',x)
