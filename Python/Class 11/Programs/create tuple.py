#Create a tuple with n elements
n=int(input('Enter the limit : '))
x=tuple([eval(input('Enter the element : ')) for i in range(n)])
print(x)
