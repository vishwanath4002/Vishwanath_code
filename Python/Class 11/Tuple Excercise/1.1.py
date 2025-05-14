f=()
n=int(input('Enter the number of terms : '))
for i in range(n):
    f+=eval(input('Enter the element : ')),
i=int(input('\nEnter the element to be found : '))
if i in f:
    print('The index of %s is %s.'%(i,f.index(i)))
else:
    print('It is not present.')
