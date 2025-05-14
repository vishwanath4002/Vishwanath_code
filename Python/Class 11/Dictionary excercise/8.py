#8
d={}
ch='yes'
print('Enter product details.')
while ch.lower()=='yes'':
    n=input('Enter the name of the product : ')
    d[n]=eval(input('Enter the price : '))
    ch=input('Do you want to continue ? (yes/no) : ')
print(d)
