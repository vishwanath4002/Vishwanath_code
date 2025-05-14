#Two lists numerator and denominator and find the lowest fraction and its index
num=[]
denum=[]
f=[]
l=int(input('Enter the limit of the list : '))
print('Numerators')
for i in range(l):
    num.append(int(input('Enter a number : ')))

print(num)
print('Denominators')
for i in range(l):
    denum.append(int(input('Enter a number greater than zero : ')))
print(denum)
for i in range(l):
    f.append(num[i]/denum[i])
print('The list of fractions is',f)
print('Smallest fraction is %s and its index is %s'%(min(f),f.index(min(f))))
