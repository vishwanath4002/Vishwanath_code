#Multiply all elements in a list
n=int(input('Enter the limit : '))
l=[eval(input('Enter the element : ')) for i in range(n)]
p=1
for i in l:
    p*=i
print('The product is : ',p)
