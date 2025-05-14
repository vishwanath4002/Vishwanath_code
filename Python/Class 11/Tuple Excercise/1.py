#Create a tuple containg the first 9 terms of the fibonacci series
f=()
a,b=0,1
for i in range(9):
    f+=a,
    c=a+b
    a,b=b,c
print(f)
n=int(input('Enter the element : '))
if n in f:
    print(f.index(n))
else:
    print('It is not present.')
